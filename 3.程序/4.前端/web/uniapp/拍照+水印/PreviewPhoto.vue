<template>

  <view class="view_page" :style="{ width: windowWidth, height: windowHeight }">

    <image :src="previewImage" class="preview-image" :style="{ width: windowWidth, height: windowHeight }"> </image>

    <!-- 隐藏canvas用于绘制水印 -->
    <canvas canvas-id="watermarkCanvas"
      :style="{ position: 'absolute', left: '-9999px', top: '-9999px', width: canvasWidth + 'px', height: canvasHeight + 'px' }"></canvas>

    <view class=" view_container" :style="{ width: windowWidth, height: windowHeight }">

      <!-- 水印 -->
      <view class="watermark">
        <text class="watermark-item">{{ address }}</text>
        <text class="watermark-item">{{ currentTime }}</text>
        <text class="watermark-item">
          {{ userInfo.realname }} {{ userInfo.employeeId }}
        </text>
      </view>

      <!-- 预览控制栏 -->
      <view class="control-bar">
        <view class="btn secondary-btn" @click="retakePhoto">取消</view>
        <view class="btn secondary-btn" @click="usePhoto">使用</view>
      </view>
    </view>
  </view>

</template>

<script>
export default {
  data() {
    return {
      userInfo: {
        realname: '张三',
        employeeId: '1001',
      },
      currentTime: '',
      address: '',
      previewImage: '',
      originalImage: '',
      canvasWidth: 0, // canvas 宽度
      canvasHeight: 0 // canvas 高度
    }
  },

  onLoad(options) {
    // 接收来自TakePhoto页面的数据
    this.userInfo = JSON.parse(decodeURIComponent(options.userInfo || '{}'));
    this.currentTime = decodeURIComponent(options.currentTime || '');
    this.address = decodeURIComponent(options.address || '');
    this.originalImage = decodeURIComponent(options.originalImage || '');
    this.previewImage = decodeURIComponent(options.originalImage || '');

    // 获取窗口尺寸
    uni.getSystemInfo({
      success: (res) => {
        this.windowWidth = res.windowWidth + 'px';
        this.windowHeight = res.windowHeight + 'px';
      }
    });
  },

  methods: {

    // 重拍 - 返回到TakePhoto页面
    retakePhoto() {
      uni.navigateBack();
    },

    // 使用照片 - 生成带水印的图片并返回
    async usePhoto() {
      uni.showLoading({
        title: '正在生成水印图片...'
      });

      try {
        // 创建canvas绘制水印
        const watermarkedImagePath = await this.addWatermarkToImage();


        this.previewImage = watermarkedImagePath;

        // 返回到TakePhoto页面
        // const checkinData = {
        //   originalImage: this.originalImage,
        //   watermarkedImage: watermarkedImagePath,
        //   watermark: {
        //     time: this.currentTime,
        //     location: this.address,
        //     user: `${this.userInfo.realname} ${this.userInfo.employeeId}`,
        //   },
        //   timestamp: new Date().getTime(),
        // }

        // // 触发返回并传递数据
        // const pages = getCurrentPages();
        // if (pages.length > 1) {
        //   const prevPage = pages[pages.length - 2]; // 上一个页面
        //   if (prevPage) {
        //     // 调用TakePhoto页面的处理方法
        //     if (typeof prevPage.handlePreviewResult === 'function') {
        //       prevPage.handlePreviewResult(checkinData);
        //     }
        //   }
        // }

        // uni.navigateBack();
      } catch (error) {
        console.error('生成水印图片失败:', error);
        uni.showToast({
          title: '生成水印图片失败',
          icon: 'none'
        });
      } finally {
        // 确保无论成功或失败都会隐藏loading
        uni.hideLoading();
      }
    },

    // 添加水印到图片
    addWatermarkToImage() {
      return new Promise((resolve, reject) => {
        // 首先确保原始图像路径有效
        if (!this.originalImage) {
          console.error('原始图像路径无效:', this.originalImage);
          reject(new Error('原始图像路径无效'));
          return;
        }

        // 使用 getImageInfo 获取图像信息
        uni.getImageInfo({
          src: this.originalImage,
          success: (imageInfo) => {
            console.log('图像信息:', imageInfo);

            // 记录canvas尺寸
            this.canvasWidth = imageInfo.width;
            this.canvasHeight = imageInfo.height;


            // 再次确认图像尺寸有效
            if (this.canvasWidth <= 0 || this.canvasHeight <= 0) {
              console.error('图像尺寸无效，无法绘制水印:', this.originalImage, this.canvasWidth, this.canvasHeight);
              reject(new Error('图像尺寸无效'));
              return;
            }
            console.info('图像尺寸配置完成:', this.originalImage, this.canvasWidth, this.canvasHeight);

            this.$nextTick(() => {
              console.info('图像开始绘制水印:', this.originalImage, this.canvasWidth, this.canvasHeight);
              const ctx = uni.createCanvasContext('watermarkCanvas', this);

              const systemInfo = uni.getSystemInfoSync()

              const ratio = systemInfo.windowWidth / 750;
              const dpr = systemInfo.pixelRatio
              const fontSize = 28 * ratio * dpr;      // 28rpx → px
              const padding = 10 * ratio * dpr;       // 10rpx → px
              const lineHeight = fontSize + 8 * ratio* dpr;

              // 绘制图片
              ctx.drawImage(this.originalImage, 0, 0, this.canvasWidth, this.canvasHeight);

              // 设置文字样式
              ctx.setFillStyle('rgba(238, 242, 6, 1)');
              ctx.setFontSize(fontSize);
              ctx.setTextAlign('right');
              ctx.setTextBaseline('top');

              // 绘制文字
              ctx.fillText(this.address, this.canvasWidth - padding, padding);
              ctx.fillText(this.currentTime, this.canvasWidth - padding, padding + lineHeight);
              ctx.fillText(`${this.userInfo.realname} ${this.userInfo.employeeId}`,
                this.canvasWidth - padding, padding + lineHeight * 2);

              ctx.draw(true, () => {
                uni.canvasToTempFilePath({
                  x: 0,
                  y: 0,
                  width: this.canvasWidth,
                  height: this.canvasHeight,
                  destWidth: this.canvasWidth,
                  destHeight: this.canvasHeight,
                  canvasId: 'watermarkCanvas',
                  success: (res) => resolve(res.tempFilePath),
                  fail: (error) => reject(error)
                }, this);
              });
            });
          },
          fail: (error) => {
            console.error('获取图片信息失败:', error, this.originalImage);
            reject(error);
          }
        });
      });
    }
  }
}
</script>

<style lang="scss" scoped>
.view_page {
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #000;
  width: 100%;
  height: 100vh;

  .h5-camera-placeholder {
    flex: 1;
    z-index: 10;
    align-items: center;
    justify-content: center;
    font-size: 32rpx;
    color: #ffffff;
  }

  .preview-image {
    position: absolute;
    left: 0;
    top: 0;
    width: 100%;
    height: 100%;
    z-index: 10;
    object-fit: cover;
  }

  .view_container {
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    display: flex;
    flex-direction: column;
    justify-content: space-between;

    .watermark {
      position: absolute;
      top: 10rpx;
      right: 10rpx;
      z-index: 20;

      .watermark-item {
        display: block;
        margin-bottom: 12rpx;
        color: rgb(238, 242, 6);
        font-size: 28rpx;
        text-align: right;
      }
    }

    .control-bar {
      position: absolute;
      left: 0;
      bottom: 0;
      z-index: 30;
      width: 100%;
      height: 400rpx;
      display: flex;
      flex-direction: row;
      align-items: center;
      justify-content: space-around;

      .btn {
        display: flex;
        align-items: center;
        justify-content: center;

        &.empty-btn {
          width: 80rpx;
          height: 80rpx;
        }

        &.flip-btn {
          width: 80rpx;
          height: 80rpx;
        }

        &.take-btn {
          width: 140rpx;
          height: 140rpx;
        }

        &.secondary-btn {
          height: 88rpx;
          width: 200rpx;
          margin: 0 16rpx;
          font-size: 28rpx;
          color: #333333;
          background-color: #f5f5f5;
          border: 1rpx solid #d9d9d9;
          border-radius: 8rpx;
          box-shadow: 0 2rpx 8rpx rgba(0, 0, 0, 0.15);
        }
      }

    }
  }
}
</style>