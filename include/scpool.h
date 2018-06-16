//  SDBC 7.3 ��ά���ӳ�
//  ֧�ֽ���·�ɡ����ؾ���/�ݴ�����ʽ���ӳ�
#ifndef SCPOOL
#define SCPOOL

typedef struct rs {
	int next;
	int pool_no; //relation to D_NODE
	int path_no;
	T_Connect Conn;
	T_CLI_Var cli;
	int (*timeout_deal)(struct rs *rs);
	INT64 timestamp;
} resource;

#ifdef __cplusplus

extern "C" {
#endif

//scpool.c
// ctx_flag=0 use as midsc; !=0 as client
int set_SC_loglevel(int new_loglevel);
int scpool_init(int ctx_flag);
void scpool_free(void);
void scpool_check(void);

resource * get_path_resource(int poolno,int path_no,int flg);
int getPathNum(int poolno);

//flg>0:æʱ�ȴ�flg�Σ�ÿ��6��,flg=0,���ȴ�,flg=-1��Զ�ȴ�
//return��NULLû�п��е�����,-1:��������,����:��������
T_Connect * get_SC_connect(int poolno,int flg);

void release_SC_connect(T_Connect **Connect,int poolno);
void release_SC_resource(resource **rsp);
resource * get_SC_by_weight(int path_no,int flg);
int get_scpool_no(int d_node);
int get_scpoolnum(void);
char *get_SC_DBLABEL(int poolno);
int get_total_conn_num(int poolno);

//mod_sc.c
void wpool_free(void);
int scpool_MGR(int TCBno,int poolno,T_Connect **connp,int (*call_back)(T_Connect *,T_NetHead *));
//midsc.c
int bind_sc(int TCBno,T_Connect *conn);
int unbind_sc(int TCBno);

#ifdef __cplusplus
}
#endif

#endif 
