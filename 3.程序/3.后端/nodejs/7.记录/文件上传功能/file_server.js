const express = require('express');
const multer = require('multer');
const path = require('path');
const fs = require('fs').promises;
const iconv = require('iconv-lite');

// 创建Express应用
const app = express();
const port = 3000;

// 允许跨域请求的中间件
app.use((req, res, next) => {
  res.setHeader('Access-Control-Allow-Origin', '*');
  res.setHeader('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');
  res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');
  res.setHeader('Access-Control-Allow-Credentials', true);
  
  if (req.method === 'OPTIONS') {
    res.sendStatus(200);
  } else {
    next();
  }
});
// 自定义Multer文件名解码函数
function decodeFilename(filename) {
  try {
      // 尝试解码可能被错误编码的文件名
      // 这里假设原始编码是UTF-8，但被错误地以ISO-8859-1处理
      const buffer = Buffer.from(filename, 'binary');
      return iconv.decode(buffer, 'utf8');
  } catch (error) {
      console.warn('文件名解码失败，使用原始文件名', error);
      return filename;
  }
}
// 配置Multer存储引擎
const storage = multer.diskStorage({
  destination: async (req, file, cb) => {
    const uploadDir = path.join(__dirname, 'uploads');
    
    // 确保上传目录存在
    try {
      await fs.access(uploadDir);
    } catch (error) {
      await fs.mkdir(uploadDir, { recursive: true });
    }
    
    cb(null, uploadDir);
  },
    filename: (req, file, cb) => {
    const fileName = decodeFilename(file.originalname);
    const extname = path.extname(file.originalname);
    console.log('上传的文件名:', fileName);
    cb(null, fileName+extname);
  }
});

// 创建Multer实例，添加文件类型过滤
const upload = multer({
  storage: storage,
  limits: {
    fileSize: 100 * 1024 * 1024 // 100MB
  },
});

// 处理文件上传的路由
app.post('/upload', upload.array('files'), (req, res) => {
  try {

    if (!req.files || req.files.length === 0) {
      return res.status(400).json({ error: '未上传任何文件' });
    }
    
    const fileNames = req.files.map(file => file.filename);
    
    // 这里可以添加Excel文件处理逻辑，如使用xlsx或exceljs库解析数据
    
    res.status(200).json({
      message: `成功上传 ${req.files.length} 个Excel文件`,
      files: fileNames
    });
  } catch (error) {
    console.error('文件上传错误:', error);
    res.status(500).json({ error: '服务器内部错误' });
  }
});

// 静态文件服务，用于访问上传的文件
app.use('/uploads', express.static(path.join(__dirname, 'uploads')));

// 启动服务器
app.listen(port, () => {
  console.log(`服务器运行在 http://localhost:${port}`);
});    