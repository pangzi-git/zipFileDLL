#ifndef _INTERFACE_H
#define _INTERFACE_H
//////////////////////////////////////////////////////////////////////////
class CLogInInterface
{
public:
	virtual void closefile() = 0;							//暂不用
	virtual int InitLogin() = 0;							//初始化操作员表
	virtual int QueryLogin(char *pLoginId,char **ppData) = 0;//根据操作员编号查询操盘员
	virtual int AddLogin(char *pData,int nSize) = 0;	//加入操作员
	virtual int Update(char *pData,int nSize) = 0;		//修改操作员信息
	virtual int increaseLoginCount(char *pLoginId) = 0;	//增加操作员已采集记录数
	virtual int QueryAllLogin(LPVOID *p) = 0;			//查询所有操作员信息
	virtual int QueryLoginCount() = 0;					//查询操作员数量
	virtual int QueryLoginByCountyId(char *pCountId,LPVOID *p) = 0;	//查询该乡镇所有操作员信息
	virtual int QueryLoginCountByCountyId(char *pCountId) = 0;		//查询该乡镇操作员数量
	virtual void SetLogHandle(void *hlog) = 0;

};
class CUerInfoInterface
{
public:

	virtual int AddMutiUserInfo(char *pBuffer,int nCount) = 0;
	virtual int QueryUserInfoHead(char **pBuffer) = 0;
	virtual int AddUserInfo(char *pBuffer,int nSize) = 0;
	virtual int QueryUnCollectedCount() = 0;					//查询
	virtual int SetCollectFlag(char *pUserId,int nFlag) = 0;	//设置已采集标志,nFlag 0未采集，1已采集，2已上传
	virtual int LoadUserInfo() = 0;								//导入数据
	virtual int QueryCollectedCount() = 0;						//查询所有已采集记录数
	virtual int QueryUnCollected(LPVOID *p) = 0;				//查询所有未采集记录
	virtual int QueryCollected(LPVOID *p) = 0;					//查询所有已采集记录
	virtual void SetLoginName(char *pName) = 0;					//设置登录用户名
	virtual int QueryUserInfo(int nType,char *pUserId,char** pData) = 0;//nType,1社保号，2身份证号
	virtual void ReleaseMemory() = 0;							//释放句柄
	virtual int SetCollectedToUpload() = 0;						//将所有已采集数据标志改为已上传
	virtual void SetLogHandle(void *hlog) = 0;					//设置日志句柄
	//virtual int QueryUnCollectedCount() = 0;					//查询未采集记录数
};
class CCollectInfoInterface
{
public:
	virtual int LoadCollected() = 0;
	virtual int QueryCollected(int nType,char *pUserId,char *pData,int nSize) = 0;
	virtual int QueryRecordSize(int nType,char *pUserId) = 0;
	virtual int DeleteCollected(char *pUserid) = 0;
	virtual void SetLoginName(char *pName) = 0;
	virtual int MoveFileToBak(char *pUpLoadFile,int nSize) = 0;
	virtual int MoveFileToUpload() = 0;
	virtual int GetAllUpLoadFileCount() = 0;
	virtual int GetAllUpLoadFileName(char *pNameList,int nSize) = 0;
	virtual int AddCollected(char *pData,int nSize) = 0;
	virtual int QueryPreCollectedId(int nType,char *pUserId,char *pId,int nSize) = 0;
	virtual int QueryNextCollectedId(int nType,char *pUserId,char *pId,int nSize) = 0;
	virtual int GetCollectedByIdx(int nIdx,char *pData) = 0;//根据id取数据信息
	virtual int GetCollectedSizeByIdx(int nIdx) = 0; //根据索引取得数据大小（包括数据头）
	virtual int QueryRecordCount() = 0;
	virtual int LoadUploadCollected(char *pIndxFileName) = 0;								//导入上传之后的索引文件
	virtual void ReleaseMemory() = 0; 
	virtual int CopyCollectedFile(char *pSourceName,char *pDestName) = 0;				//移动已采集文件
	virtual int IsTwoFileExist(char *pFileName) = 0;										//判断文件是否存在
	virtual int GetLoginNameFromHead(char *pLoginName,int nSize) = 0;								//在索引文件头中查询操作员ID
	virtual void SetLogHandle(void *hlog) = 0;
	virtual int MoveAnyFileToUpload(char *pSrcFileName) = 0;
	virtual void GetCurrentFileName(char *pFileName,int nLen)  = 0;											//取当前加载的文件名
	virtual int SetFileStatus(int nStatus) =0;										//设置文件状态,0未上传，1已采集未上传(移到upload目录)，2已上传
	virtual int GetFileStatus() = 0;									//查询文件status,0未上传，1已采集未上传(移到upload目录)，2已上传
	virtual int QueryCollectCount() = 0;								//查询已采集记录数
	virtual int QueryAllCollectInfo(LPVOID *p) = 0;								//查询所有已采集记录的基本信息
	virtual int SetUploadStatus(char *pUserid) = 0;					//设置记录上传状

};
//enum eLevel{ eERROR=0,	/*错误*/ eINFO,   /*信息*/eSYSTEM	/*系统*/};
class CLogInterface
{
public:
	virtual int InitLog() = 0;						//初始化日志文件
	virtual void LOG(int nLevel,char * pLogString) = 0;			//记录日志
	virtual void SetLoginName(char *pLoginName) = 0;//设置登录用户名
	virtual void CloseLog() = 0;				//关闭文件日志
	virtual void SetLogLevel(char *pLevel) = 0;
};
//////////////////////////////////////////////////////////////////////////
#define FUNC_NAME "QueryInterface"
typedef BOOL (*PQueryInterface)(CUerInfoInterface **pInterface);
typedef BOOL (*PQueryCollectInterface)(CCollectInfoInterface **pInterface);
typedef BOOL (*PLogInterface)(CLogInterface **pInterface);
typedef BOOL (*PLogInInterface)(CLogInInterface **pInterface);

#endif//_INTERFACE_H

