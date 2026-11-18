---
title: "7. 应用层"
published: 2026-11-18
category: 计算机网络
---

[返回七层总图和分层目录](/posts/network-index/)

我把这一层理解为：程序之间先约定消息的写法和含义。比如 `GET /index.html`，接收端按 HTTP 的规则读出「获取这个资源」。HTTP 规定怎么表达请求，具体想做什么还得看方法和路径。浏览器是常见的 HTTP 客户端，用代码写的客户端也能发送 HTTP 请求。

HTTPS 用 TLS 保护 HTTP 通信。DNS 常用来查询域名对应的 IP 地址。我在浏览器里输入一个网址时，如果本地没有可用的解析结果，通常要先解析域名，再向对应的服务器发请求。

相关卡片 · [HTTP](/posts/network-keywords/#http)
