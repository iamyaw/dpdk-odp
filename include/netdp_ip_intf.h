/*-
 *   BSD LICENSE
 *
 *   Copyright(c) 2010-2014 Netdp Corporation. All rights reserved.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Netdp Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


/*-
 * Copyright (c) 1982, 1986, 1993
 *  The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following edsclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following edsclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE EDSCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#ifndef __NETDP_IP_INTF_H__ 
#define __NETDP_IP_INTF_H__


#define NETDP_IP_RTF_UP     0x1   /* route usable */
#define NETDP_IP_RTF_GATEWAY    0x2   /* destination is a gateway */
#define NETDP_IP_RTF_HOST          0x4    /* host entry (net otherwise) */
#define NETDP_IP_RTF_REJECT   0x8   /* host or net unreachable */
#define NETDP_IP_RTF_DYNAMIC    0x10        /* created dynamically (by redirect) */
#define NETDP_IP_RTF_MODIFIED  0x20   /* modified dynamically (by redirect) */
#define   NETDP_IP_RTF_DONE          0x40   /* message confirmed */
/*      0x80       unused, was RTF_DELCLONE */
#define   NETDP_IP_RTF_CLONING     0x100    /* generate new routes on use */
#define   NETDP_IP_RTF_XRESOLVE   0x200   /* external daemon resolves name */
#define   NETDP_IP_RTF_LLINFO    0x400    /* generated by link layer (e.g. ARP) */
#define   NETDP_IP_RTF_STATIC    0x800    /* manually added */
#define   NETDP_IP_RTF_BLACKHOLE 0x1000   /* just discard pkts (during updates) */
#define   NETDP_IP_RTF_PROTO2    0x4000   /* protocol specific routing flag */
#define   NETDP_IP_RTF_PROTO1    0x8000   /* protocol specific routing flag */

/* XXX: temporary to stay API/ABI compatible with userland */
#define NETDP_IP_RTF_PRCLONING  0x10000   /* unused, for compatibility */

#define NETDP_IP_RTF_WASCLONED  0x20000   /* route generated through cloning */
#define NETDP_IP_RTF_PROTO3       0x40000   /* protocol specific routing flag */
/*      0x80000      unused */
#define NETDP_IP_RTF_PINNED 0x100000  /* future use */
#define NETDP_IP_RTF_LOCAL    0x200000  /* route represents a local address */
#define NETDP_IP_RTF_BROADCAST  0x400000  /* route represents a bcast address */
#define NETDP_IP_RTF_MULTICAST  0x800000  /* route represents a mcast address */
          /* 0x1000000 and up unassigned */


/**
 * Default route creation routine.
 * Creates a default route (ip addr: 0.0.0.0  netmask: 0.0.0.0)
 * pointing to a gateway with address 'gateway_addr'
 *
 * @param gateway_addr  IP address of gateway
 *
 * @return  0 - SUCCESS, non-zero - FAILURE
 *
 *
 */

int netdp_add_default_route(uint32_t gateway_addr);



/**
 * Default route deletion.
 *
 * @return  0 - SUCCESS, non-zero - FAILURE
 *
 *
 */

int netdp_del_default_route();



/**
 * Routing table addition.
 *
 * @param dest_ipaddr   ip address of the destination for which the route is being added
 * @param gateway_valid indicates whether the 'gateway_addr' is valid
 * @param gateway_addr  ip address of gateway
 * @param netmask       netmask to be used with route
 * @param flags         flags for this routing entry
 *
 * @return  0 - SUCCESS, non-zero - FAILURE
 *
 */

int netdp_add_route(uint32_t dest_ipaddr, uint8_t gateway_valid, uint32_t gateway_addr,
                                      uint32_t netmask, int flags);



/**
 * Routing table deletion.
 *
 * @param dest_ipaddr   ip address of the destination for which the route is being deleted
 * @param netmask       netmask to be used with route
 * @param flags         flags for this routing entry (same value as used during route addition)
 *
 * @return  0 - SUCCESS, non-zero - FAILURE
 *
 */

int netdp_del_route(uint32_t dest_ipaddr, uint32_t netmask, int flags);



#endif 
