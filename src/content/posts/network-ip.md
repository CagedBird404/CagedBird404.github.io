---
title: "3. 网络层"
published: 2026-11-18
category: 计算机网络
---

[返回七层总图和分层目录](/posts/network-index/)

我在网络层关注两个问题：这个 IP 包从哪里来，要往哪里去？IP 包里有源地址和目的地址。操作系统按路由表选择出口和下一跳，路由器收到包后也会根据目的 IP 继续转发。

在程序里，我可以先指定本机的某个 IP 来绑定套接字，也可以让系统按路由选择发送用的源 IP。对端 IP 则决定包最终要到哪里。IPv4 和 IPv6 可以同时存在，IPv4 的本机回环是 `127.0.0.1`，IPv6 的是 `::1`。

跨网络时，当前这一跳要先交给网关。以太网 IPv4 场景下，ARP 查的是网关的 MAC 地址，IP 包的目的地址仍然指向最终目标。

相关卡片 · [IPv4](/posts/network-keywords/#ipv4) · [IPv6](/posts/network-keywords/#ipv6) · [ARP](/posts/network-keywords/#arp) · [NDP](/posts/network-keywords/#ndp)
