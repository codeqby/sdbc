/****************************************************
 * �ٵ�AIO����AIO_fd.c���غ�ʵ�����AIO
 ***************************************************/

#include <scsrv.h>
#include <unistd.h>

int AIO_read(int fd,char *buff,size_t iosize)
{
	return read(fd,buff,iosize);
}

int AIO_write(int fd,char *buff,size_t iosize)
{
	return write(fd,buff,iosize);
}
