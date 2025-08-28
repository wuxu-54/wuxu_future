FROM nginx:alpine

# 复制前端静态文件到 Nginx 目录
COPY src/ /usr/share/nginx/html/

# 复制 Nginx 配置（处理反向代理）
COPY nginx.conf /etc/nginx/conf.d/default.conf