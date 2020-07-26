#ifndef _INTERFACE_H
#define _INTERFACE_H
//////////////////////////////////////////////////////////////////////////
class CLogInInterface
{
public:
	virtual void closefile() = 0;							//�ݲ���
	virtual int InitLogin() = 0;							//��ʼ������Ա��
	virtual int QueryLogin(char *pLoginId,char **ppData) = 0;//���ݲ���Ա��Ų�ѯ����Ա
	virtual int AddLogin(char *pData,int nSize) = 0;	//�������Ա
	virtual int Update(char *pData,int nSize) = 0;		//�޸Ĳ���Ա��Ϣ
	virtual int increaseLoginCount(char *pLoginId) = 0;	//���Ӳ���Ա�Ѳɼ���¼��
	virtual int QueryAllLogin(LPVOID *p) = 0;			//��ѯ���в���Ա��Ϣ
	virtual int QueryLoginCount() = 0;					//��ѯ����Ա����
	virtual int QueryLoginByCountyId(char *pCountId,LPVOID *p) = 0;	//��ѯ���������в���Ա��Ϣ
	virtual int QueryLoginCountByCountyId(char *pCountId) = 0;		//��ѯ���������Ա����
	virtual void SetLogHandle(void *hlog) = 0;

};
class CUerInfoInterface
{
public:

	virtual int AddMutiUserInfo(char *pBuffer,int nCount) = 0;
	virtual int QueryUserInfoHead(char **pBuffer) = 0;
	virtual int AddUserInfo(char *pBuffer,int nSize) = 0;
	virtual int QueryUnCollectedCount() = 0;					//��ѯ
	virtual int SetCollectFlag(char *pUserId,int nFlag) = 0;	//�����Ѳɼ���־,nFlag 0δ�ɼ���1�Ѳɼ���2���ϴ�
	virtual int LoadUserInfo() = 0;								//��������
	virtual int QueryCollectedCount() = 0;						//��ѯ�����Ѳɼ���¼��
	virtual int QueryUnCollected(LPVOID *p) = 0;				//��ѯ����δ�ɼ���¼
	virtual int QueryCollected(LPVOID *p) = 0;					//��ѯ�����Ѳɼ���¼
	virtual void SetLoginName(char *pName) = 0;					//���õ�¼�û���
	virtual int QueryUserInfo(int nType,char *pUserId,char** pData) = 0;//nType,1�籣�ţ�2���֤��
	virtual void ReleaseMemory() = 0;							//�ͷž��
	virtual int SetCollectedToUpload() = 0;						//�������Ѳɼ����ݱ�־��Ϊ���ϴ�
	virtual void SetLogHandle(void *hlog) = 0;					//������־���
	//virtual int QueryUnCollectedCount() = 0;					//��ѯδ�ɼ���¼��
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
	virtual int GetCollectedByIdx(int nIdx,char *pData) = 0;//����idȡ������Ϣ
	virtual int GetCollectedSizeByIdx(int nIdx) = 0; //��������ȡ�����ݴ�С����������ͷ��
	virtual int QueryRecordCount() = 0;
	virtual int LoadUploadCollected(char *pIndxFileName) = 0;								//�����ϴ�֮��������ļ�
	virtual void ReleaseMemory() = 0; 
	virtual int CopyCollectedFile(char *pSourceName,char *pDestName) = 0;				//�ƶ��Ѳɼ��ļ�
	virtual int IsTwoFileExist(char *pFileName) = 0;										//�ж��ļ��Ƿ����
	virtual int GetLoginNameFromHead(char *pLoginName,int nSize) = 0;								//�������ļ�ͷ�в�ѯ����ԱID
	virtual void SetLogHandle(void *hlog) = 0;
	virtual int MoveAnyFileToUpload(char *pSrcFileName) = 0;
	virtual void GetCurrentFileName(char *pFileName,int nLen)  = 0;											//ȡ��ǰ���ص��ļ���
	virtual int SetFileStatus(int nStatus) =0;										//�����ļ�״̬,0δ�ϴ���1�Ѳɼ�δ�ϴ�(�Ƶ�uploadĿ¼)��2���ϴ�
	virtual int GetFileStatus() = 0;									//��ѯ�ļ�status,0δ�ϴ���1�Ѳɼ�δ�ϴ�(�Ƶ�uploadĿ¼)��2���ϴ�
	virtual int QueryCollectCount() = 0;								//��ѯ�Ѳɼ���¼��
	virtual int QueryAllCollectInfo(LPVOID *p) = 0;								//��ѯ�����Ѳɼ���¼�Ļ�����Ϣ
	virtual int SetUploadStatus(char *pUserid) = 0;					//���ü�¼�ϴ�״

};
//enum eLevel{ eERROR=0,	/*����*/ eINFO,   /*��Ϣ*/eSYSTEM	/*ϵͳ*/};
class CLogInterface
{
public:
	virtual int InitLog() = 0;						//��ʼ����־�ļ�
	virtual void LOG(int nLevel,char * pLogString) = 0;			//��¼��־
	virtual void SetLoginName(char *pLoginName) = 0;//���õ�¼�û���
	virtual void CloseLog() = 0;				//�ر��ļ���־
	virtual void SetLogLevel(char *pLevel) = 0;
};
//////////////////////////////////////////////////////////////////////////
#define FUNC_NAME "QueryInterface"
typedef BOOL (*PQueryInterface)(CUerInfoInterface **pInterface);
typedef BOOL (*PQueryCollectInterface)(CCollectInfoInterface **pInterface);
typedef BOOL (*PLogInterface)(CLogInterface **pInterface);
typedef BOOL (*PLogInInterface)(CLogInInterface **pInterface);

#endif//_INTERFACE_H

