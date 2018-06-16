/*******************************************************
 * Secure Database Connect
 * SDBC 6.0 for ORACLE 
 * 2012.09.15 by ylh
 *******************************************************/

#ifndef SDBCDEF
#define SDBCDEF

#include <sqli.h>
#include <scsrv.h>
#include <json_pack.h>

#ifdef __cplusplus
extern "C" {
#endif
/* Server database interface functions */
extern int SQL_OpenDatabase(T_Connect *connect,T_NetHead *NetHead);
extern int SQL_Prepare(T_Connect *connect,T_NetHead *NetHead);
extern int SQL_Select(T_Connect *connect,T_NetHead *NetHead);
extern int SQL_Exec(T_Connect *connect ,T_NetHead *NetHead);
extern int SQL_Fetch(T_Connect *connect,T_NetHead *NetHead);
extern int SQL_Close(T_Connect *connect,T_NetHead *NetHead);
extern int SQL_RPC(T_Connect *connect,T_NetHead *NetHead);
extern int SQL_CloseDatabase(T_Connect *connect,T_NetHead *NetHead);
extern int SQL_EndTran(T_Connect *connect,T_NetHead *NetHead);
extern int locktab(T_Connect *connect,T_NetHead *NetHead);
//extern int SQL_Quit(T_SRV_Var *);
extern const char * _get_data_type_str(int dtype);
/************************************************
 * mod_DB.c:���ݿ����ӳظ߼�������
 ************************************************/ 
/**
 * DB_connect_MGR:�����ݿ����ӳظ߼��������������ݿ�����(mod_DB.c)
 * ����ֵ:0:�ɹ�ȡ�����ӡ�1:����æ���������������У�-1:����
 */
int DB_connect_MGR(int TCBno,int poolno,T_SQL_Connect **sqlp,sdbcfunc call_back);
/* �ͷ�mod_DB�Ķ��нṹ   */
void mod_DB_free(void);
/* ȡ�������ṹ */
T_SRV_Var * get_SRV_Var(int TCBno);
/******************************************************
 * bind_DB.c
 * ���mod_DB,����ȡ�����ݿ����Ӻ󣬴��ݸ���Ӧ��TCB,
 * �����Ӧ��TCB�г�ȥ֮�� ���Ա�����Ӧ����������
 *****************************************************/
int bind_DB(int TCBno,T_SQL_Connect *sql);
int unbind_DB(int TCBno);

int dui(T_Connect *conn,T_NetHead *nethead);
int page_select(T_Connect *conn,T_NetHead *nethead);

//��շ������е�ģ���
int tpl_cancel(T_Connect *conn,T_NetHead *head);
//ȡ���ݿ��ģ��
//head->data="����1,����2,,,"
//����JSON����:{����:[ģ��],����:[ģ��],...}
int get_tpl(T_Connect *conn,T_NetHead *head);

#ifdef __cplusplus
}
#endif

#endif
