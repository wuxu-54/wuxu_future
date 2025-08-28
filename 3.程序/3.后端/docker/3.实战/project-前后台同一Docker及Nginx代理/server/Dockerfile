FROM node:21.5.0-alpine

WORKDIR /app
COPY package*.json ./
RUN npm install --production

COPY . .
EXPOSE 3000
CMD ["npm", "start"]