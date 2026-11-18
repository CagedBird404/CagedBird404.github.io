---
title: "2. 数据链路层"
published: 2026-11-18
category: 计算机网络
---

[返回七层总图和分层目录](/posts/network-index/)

我把链路层的范围记成「当前这一跳」。在以太网里，系统把 IP 包装进帧，帧头记录这段链路上的源 MAC 和目标 MAC。同一链路内发送时，目标 MAC 可以是接收电脑的。去其他网络时，发出的第一帧通常先交给网关。

交换机主要根据帧的目标 MAC 转发。路由器把包转到下一段链路时，会为那一跳重新封装。这样就能分清：目的 IP 指向数据要去哪里，目标 MAC 指明这一帧要先交给谁。

相关卡片 · [ARP](/posts/network-keywords/#arp) · [MAC 地址](/posts/network-keywords/#mac)
