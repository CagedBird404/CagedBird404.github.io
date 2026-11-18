---
title: "OSI 七层网络模型"
published: 2026-11-18
category: 计算机网络
description: "我用七层模型理解一次网络通信里各部分的分工。"
---

[返回计算机网络专题](/posts/network-index/)

我用七层模型理解一次网络通信里各部分的分工。

| 层次 | 我怎么理解 |
| --- | --- |
| 7. 应用层 | 规定消息怎么写、怎么理解。比如 HTTP 的 `GET /index.html` 表示请求获取一个资源，DNS 可以用来查询域名对应的地址。 |
| 6. 表示层 | 处理数据如何表示，比如编码、格式转换，以及按需压缩和加解密。 |
| 5. 会话层 | 建立、管理和结束会话，协调一段持续的交互。 |
| 4. 传输层 | 在两端应用之间传输数据，[TCP 与 UDP](/posts/network-transport/)是两种常见协议。 |
| 3. 网络层 | IP 数据包带有源和目的 IP，路由器根据目的地址决定往哪里转发。 |
| 2. 数据链路层 | 把数据帧送过当前一跳，例如用以太网帧交给下一台设备。 |
| 1. 物理层 | 用电信号、光信号或无线电传输比特。 |

我把发送过程理解成从上往下封装。以 HTTP 经 TCP 和 IPv4 传输为例，TCP 加上源端口和目的端口，IP 再加上源地址和目的地址，链路层把它装进帧。到达接收端后，从下往上解析，应用最终按 HTTP 的规则理解消息。

实际写程序时，我常接触的是 TCP/IP 协议栈。OSI 的上三层可以帮助我区分消息格式、编码和会话各自负责什么。

## 关键词

[OSI](/posts/network-keywords/#osi) · [TCP](/posts/network-keywords/#tcp) · [UDP](/posts/network-keywords/#udp) · [端口](/posts/network-keywords/#端口) · [IPv4](/posts/network-keywords/#ipv4)
