---
title: 计算机网络知识点卡片
published: 2026-11-18
category: 计算机网络
---

[返回专题主文](/posts/network-index/)

[OSI](#osi) · [HTTP](#http) · [TCP](#tcp) · [UDP](#udp) · [Socket](#socket) · [端口](#端口) · [bind()](#bind) · [sendto()](#sendto) · [recvfrom()](#recvfrom) · [IPv4](#ipv4) · [IPv6](#ipv6) · [ARP](#arp) · [MAC 地址](#mac) · [NDP](#ndp)

<a id="osi"></a>

## OSI 是什么

> 我用七层描述通信分工。发送时逐层封装，接收时逐层解析。

[查看相关小专题](/posts/network-osi/)

<a id="http"></a>

## HTTP 是什么

> 应用层协议，规定请求和响应的格式与含义。GET 表示请求获取目标资源。

[查看相关小专题](/posts/network-osi/)

<a id="tcp"></a>

## TCP 是什么

> 面向连接，提供可靠、有序的字节流。应用自行划分消息边界。

[查看相关小专题](/posts/network-transport/)

<a id="udp"></a>

## UDP 是什么

> 按数据报传输，协议本身不保证送达、顺序或去重。

[查看相关小专题](/posts/network-transport/)

<a id="socket"></a>

## Socket 是什么

> 程序使用网络能力的通信端点。程序把 socket() 返回的句柄交给系统接口，指定操作哪个端点。

[查看相关小专题](/posts/network-socket/)

<a id="端口"></a>

## 端口 是什么

> TCP 或 UDP 的通信端点编号。系统还会结合地址和协议等信息来分发数据。

[查看相关小专题](/posts/network-socket/)

<a id="bind"></a>

## bind() 是什么

> 关联套接字和一个本地地址。通配地址 0.0.0.0 用于绑定本机 IPv4 地址范围。

[查看相关小专题](/posts/network-socket/)

<a id="sendto"></a>

## sendto() 是什么

> 把一条 UDP 数据报发送到指定 IP 和端口。每次调用可以指定不同目标。

[查看相关小专题](/posts/network-socket/)

<a id="recvfrom"></a>

## recvfrom() 是什么

> 读取一条数据报，并可取得发送方的 IP 和端口。返回值给出实际收到的字节数。

[查看相关小专题](/posts/network-socket/)

<a id="ipv4"></a>

## IPv4 是什么

> 使用 32 位地址。本机回环测试常用 127.0.0.1。

[查看相关小专题](/posts/network-ip/)

<a id="ipv6"></a>

## IPv6 是什么

> 使用 128 位地址，可以与 IPv4 同时使用。回环地址是 ::1。

[查看相关小专题](/posts/network-ip/)

<a id="arp"></a>

## ARP 是什么

> 在本地链路上查找下一跳 IPv4 对应的 MAC 地址。目标跨网时，通常查网关。

[查看相关小专题](/posts/network-ip/)

<a id="mac"></a>

## MAC 地址 是什么

> 以太网用它标识链路上的发送和接收接口。我用它理解一帧交给谁。

[查看相关小专题](/posts/network-ip/)

<a id="ndp"></a>

## NDP 是什么

> IPv6 的邻居发现机制，可以发现本地链路上邻居的链路层地址。

[查看相关小专题](/posts/network-ip/)
