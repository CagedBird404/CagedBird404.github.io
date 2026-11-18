---
title: "IPv4、IPv6 与 ARP"
published: 2026-11-18
category: 计算机网络
description: "我用本机、局域网和跨网三个场景理解地址与转发。"
---

[返回计算机网络专题](/posts/network-index/)

我用本机、局域网和跨网三个场景理解地址与转发。

## IPv4 和 IPv6

IPv4 地址有 32 位，例如 `192.168.1.10`。IPv6 地址有 128 位，用十六进制和冒号表示。一个网络接口可以同时拥有两种地址。本机测试可以用 IPv4 的 `127.0.0.1` 或 IPv6 的 `::1`。

## ARP 查的是下一跳的 MAC 地址

在以太网里，IP 数据包记录源和目的 IP，当前这一跳还需要知道该把帧交给哪个 MAC 地址。

- 如果目标就在当前链路上，我用 ARP 解析目标的 IPv4 地址。
- 如果目标在别的网络，我用 ARP 解析下一跳（通常是默认网关）的 IPv4 地址。在这台电脑发出的 IP 包里，目的 IP 仍然是最终目标。

ARP 的结果可以暂存在缓存。IPv6 通过邻居发现（NDP）完成类似的地址解析。

[回到 OSI 七层网络模型](/posts/network-osi/)

## 关键词

[OSI](/posts/network-keywords/#osi) · [IPv4](/posts/network-keywords/#ipv4) · [IPv6](/posts/network-keywords/#ipv6) · [ARP](/posts/network-keywords/#arp) · [NDP](/posts/network-keywords/#ndp)
