
include $(top_srcdir)/Makefile.am.common

#--------------------------------------
# Atomix project I/O library 
#--------------------------------------
noinst_LIBRARIES = lib.axiolib.a	#GNU naming convention
lib_axiolib_a_SOURCES = \
  IO_util.c \
  IO_BufferToPkt_i.c \
  IO_CHDRPktToSampleBuf_i.c \
  IO_EthWriteCplx16Buf80_i.c \
  IO_EthUtil.c \
  IO_EthRawTx_i.c \
  IO_EthStaticARPTx_i.c

#

lib_axiolib_a_CFLAGS = -I"`_cygpath -m ${ORILIB_INC_DIR}`"

dist_doc_DATA = README.md

clean:
	rm $(top_srcdir)/*.pp
