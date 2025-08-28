const express = require('express');
const app = express();
const port = 3000;

// 允许跨域（生产环境建议用 Nginx 代理避免跨域）
app.use((req, res, next) => {
  res.setHeader('Access-Control-Allow-Origin', '*');
  res.setHeader('Access-Control-Allow-Methods', 'GET, POST');
  res.setHeader('Access-Control-Allow-Headers', 'Content-Type');
  next();
});

// 示例接口
app.get('/api/data', (req, res) => {
  res.json({ message: 'Hello from Node.js Server!' });
});

app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});