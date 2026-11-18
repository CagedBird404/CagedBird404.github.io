---
title: "Socket、IP 和端口"
published: 2026-11-18
category: 计算机网络
description: "我把套接字理解为程序通过操作系统收发网络数据的入口。"
---

[返回计算机网络专题](/posts/network-index/)

我把套接字理解为程序通过操作系统收发网络数据的入口。

调用 `socket()` 时，程序向操作系统申请套接字，拿到一个句柄。创建 IPv4 UDP 套接字时，可以指定 `AF_INET`、`SOCK_DGRAM` 和 `IPPROTO_UDP`。这时协议已经确定，本地端口可以稍后分配。

- `bind(s, 本地地址)` 将本地 IP 和端口关联到套接字。
- `sendto(s, 数据, 对方地址)` 指定这一次 UDP 数据报发给谁。没提前绑定时，系统通常会自动分配本地端口。
- `recvfrom(s, ...)` 读取数据报，并可以取得发送方的 IP 和端口。

我用两个变量分清方向：`serverAddr` 是发送目标，`addrFrom` 由 `recvfrom()` 填写。比如在同一台电脑上调试，客户端可以发到 `127.0.0.1:5000`。服务端收到后，按 `addrFrom` 里的地址和端口回复。

一个进程可以持有多个套接字。TCP 服务端也可以用一个套接字监听端口，用 `accept()` 返回的套接字分别和客户端通信。这些连接可以共用服务端的监听端口。

进程和线程属于操作系统的分工。进程持有资源，线程由系统调度。在一个逻辑 CPU 上交替执行是并发，在不同逻辑 CPU 上同一时刻执行是并行。

[接着看 IPv4、IPv6 与 ARP](/posts/network-ip/)

## 关键词

[TCP](/posts/network-keywords/#tcp) · [UDP](/posts/network-keywords/#udp) · [端口](/posts/network-keywords/#端口) · [IPv4](/posts/network-keywords/#ipv4) · [IPv6](/posts/network-keywords/#ipv6) · [ARP](/posts/network-keywords/#arp)
