/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
opera_arquivos_100(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		arquivo criar_arquivo_100_arg;
		arquivo deletar_arquivo_100_arg;
		arquivo copiar_arquivo_100_arg;
		arquivo escrever_arquivo_100_arg;
		arquivo ler_arquivo_100_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case criar_arquivo:
		_xdr_argument = (xdrproc_t) xdr_arquivo;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) criar_arquivo_100_svc;
		break;

	case deletar_arquivo:
		_xdr_argument = (xdrproc_t) xdr_arquivo;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) deletar_arquivo_100_svc;
		break;

	case copiar_arquivo:
		_xdr_argument = (xdrproc_t) xdr_arquivo;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) copiar_arquivo_100_svc;
		break;

	case escrever_arquivo:
		_xdr_argument = (xdrproc_t) xdr_arquivo;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) escrever_arquivo_100_svc;
		break;

	case ler_arquivo:
		_xdr_argument = (xdrproc_t) xdr_arquivo;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) ler_arquivo_100_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (opera_arquivos, opera_arquivos1);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, opera_arquivos, opera_arquivos1, opera_arquivos_100, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (opera_arquivos, opera_arquivos1, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, opera_arquivos, opera_arquivos1, opera_arquivos_100, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (opera_arquivos, opera_arquivos1, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
