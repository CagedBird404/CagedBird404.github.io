---
title: "TCP 与 UDP"
published: 2026-11-18
category: 计算机网络
description: "我把可靠性、速度和安全性分开理解。"
---

[返回计算机网络专题](/posts/network-index/)

我把可靠性、速度和安全性分开理解。

## TCP

TCP 先建立连接，随后提供可靠、有序的**字节流**。丢失的数据可以重传。应用要自己划分消息边界，例如用长度字段或换行符，因为一次发送和一次接收的字节数可能不同。

## UDP

UDP 按**数据报**传输，可以用 `sendto()` 直接给指定地址发送。协议本身不保证送达、顺序或去重。如果应用需要确认或重试，就要在上层实现。

我选择协议时会先看业务能不能接受丢包、是否要求顺序。实际速度取决于网络和应用实现，加密则由 TLS 等机制提供。

[接着看 Socket、IP 和端口](/posts/network-socket/)

## 关键词

[TCP](/posts/network-keywords/#tcp) · [UDP](/posts/network-keywords/#udp) · [Socket](/posts/network-keywords/#socket) · [端口](/posts/network-keywords/#端口)
