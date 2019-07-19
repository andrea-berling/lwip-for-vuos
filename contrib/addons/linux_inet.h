/**
 * @file
 * This file (together with sockets.h) aims to provide structs and functions from
 * - arpa/inet.h
 * - netinet/in.h
 *
 */

/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef LWIP_HDR_MY_INET_H
#define LWIP_HDR_MY_INET_H
#include <linux/in6.h>
#define IN6ADDR_ANY_INIT {{{0,0,0,0}}}
#include <sys/socket.h>
#include <linux/in.h>
#include <lwip/ip6_addr.h>
#include <lwip/ip_addr.h>
#include <errno.h>

#define inet6_addr_from_ip6addr(target_in6addr, source_ip6addr) {(target_in6addr)->in6_u.u6_addr32[0] = (source_ip6addr)->addr[0]; \
                                                                 (target_in6addr)->in6_u.u6_addr32[1] = (source_ip6addr)->addr[1]; \
                                                                 (target_in6addr)->in6_u.u6_addr32[2] = (source_ip6addr)->addr[2]; \
                                                                 (target_in6addr)->in6_u.u6_addr32[3] = (source_ip6addr)->addr[3];}

#define inet6_addr_to_ip6addr(target_ip6addr, source_in6addr)   {(target_ip6addr)->addr[0] = (source_in6addr)->in6_u.u6_addr32[0]; \
                                                                 (target_ip6addr)->addr[1] = (source_in6addr)->in6_u.u6_addr32[1]; \
                                                                 (target_ip6addr)->addr[2] = (source_in6addr)->in6_u.u6_addr32[2]; \
                                                                 (target_ip6addr)->addr[3] = (source_in6addr)->in6_u.u6_addr32[3]; \
                                                                 ip6_addr_clear_zone(target_ip6addr);}

#define inet_addr_from_ip4addr(target_inaddr, source_ipaddr) ((target_inaddr)->s_addr = ip4_addr_get_u32(source_ipaddr))
#define inet_addr_to_ip4addr(target_ipaddr, source_inaddr)   (ip4_addr_set_u32(target_ipaddr, (source_inaddr)->s_addr))

#endif /* LWIP_HDR_MY_INET_H */
