from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# 设置 WebDriver 的路径（如果是 ChromeDriver）
driver_path = 'D:\googleweb\chromedriver-win64\chromedriver'
# 注意：浏览器内核与chromedriver必须对应上
# chromedriver下载地址： https://googlechromelabs.github.io/chrome-for-testing/
options = webdriver.ChromeOptions()
driver = webdriver.Chrome(options)




# 打开网页
driver.get('https:www.baidu.com/')

try:
    input("开始调试")

    search_box = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.CLASS_NAME, "className"))
    )
    search_box.send_keys("Selenium Python")

except Exception as e:
    print(e)

finally:
    # 关闭浏览器
    # driver.quit()
    print("结束调试")