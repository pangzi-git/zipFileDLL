#include "cPackFile.h"    


//将文件添加到zip文件中，注意如果源文件srcFile为空则添加空目录    
//fileNameInZip: 在zip文件中的文件名，包含相对路径    
void cPackFile::AddFileToZip(zipFile zf, const char* fileNameInZip, const char* srcFile)    
{    
	FILE* srcfp = NULL;        

	//初始化写入zip的文件信息
	zip_fileinfo zi;        
	zi.tmz_date.tm_sec = zi.tmz_date.tm_min = zi.tmz_date.tm_hour =    
		zi.tmz_date.tm_mday = zi.tmz_date.tm_mon = zi.tmz_date.tm_year = 0;    
	zi.dosDate = 0;    
	zi.internal_fa = 0;    
	zi.external_fa = 0;    

	//如果srcFile为空，加入空目录    
	char new_file_name[MAX_PATH];    
	memset(new_file_name, 0, sizeof(new_file_name));    
	strcat_s(new_file_name, fileNameInZip);    
	if (srcFile == NULL)    
	{    
		strcat_s(new_file_name, "/");    
	}    

	//在zip文件中创建新文件    
	zipOpenNewFileInZip(zf, new_file_name, &zi, NULL, 0, NULL, 0, NULL, Z_DEFLATED, Z_DEFAULT_COMPRESSION);    

	if (srcFile != NULL)    
	{    
		//打开源文件    
		//srcfp = fopen(srcFile, "rb");
		fopen_s(&srcfp,srcFile,"rb");
		if (srcfp == NULL)    
		{    
			printf("无法添加文件: %s !\n",srcFile);    
			zipCloseFileInZip(zf); //关闭zip文件    
			return;    
		}    

		//读入源文件并写入zip文件    
		char buf[100*1024]; //buffer    
		int numBytes = 0;    
		while( !feof(srcfp) )    
		{    
			numBytes = fread(buf, 1, sizeof(buf), srcfp);    
			zipWriteInFileInZip(zf, buf, numBytes);    
			if( ferror(srcfp) )    
				break;    
		}    

		//关闭源文件    
		fclose(srcfp);    
	}    

	//关闭zip文件    
	zipCloseFileInZip(zf);    
}    


//递归添加子目录到zip文件    
void cPackFile::CollectFilesInDirToZip(zipFile zf, const char * strPath, const char * parentDir) 
{
	//AddFileToZip(zf, fullPath, NULL); //在zip文件中生成根目录
	//USES_CONVERSION; 
	char allfilestr[MAX_PATH];

	strcpy_s(allfilestr,strPath);
	strcat_s(allfilestr,"//*.*");//find all files

	long Handle;
	struct _finddata_t FileInfo;

	if((Handle=_findfirst(allfilestr,&FileInfo))==-1L)//目录不存在
		return;

	char currentPath[MAX_PATH];
	char fullPath[MAX_PATH];

	do 
	{
		if(strlen(FileInfo.name)==1&&FileInfo.name[0]=='.'
			||strlen(FileInfo.name)==2&&FileInfo.name[0]=='.'&&FileInfo.name[1]=='.')
			continue;//当前文件夹 上一层目录

		if (strlen(parentDir)!=0)
		{
			strcpy_s(fullPath,parentDir);
			strcat_s(fullPath,"/");
			strcat_s(fullPath,FileInfo.name);//生成在zip文件中的相对路径
		}
		else
			strcpy_s(fullPath,FileInfo.name);

		strcpy_s(currentPath,strPath);
		strcat_s(currentPath,"//");
		strcat_s(currentPath,FileInfo.name);

		if(FileInfo.attrib & _A_SUBDIR)// is a directory
		{
			AddFileToZip(zf, fullPath, NULL); //在zip文件中生成目录结构
			CollectFilesInDirToZip(zf, currentPath, fullPath);//递归收集子目录文件    
			continue;    
		} 
		AddFileToZip(zf, fullPath, currentPath); //将文件添加到zip文件中
	} while ( _findnext(Handle,&FileInfo)==0 );//find next file
}

//将某个目录或者文件(dirName)压缩为zipFileName(.zip)文件
int  cPackFile::CreateZipFromDir(const char * dirName, const char * zipFileName)
{    
	long Handle;
	struct _finddata_t FileInfo;

	if((Handle=_findfirst(dirName,&FileInfo))==-1L)//目录不存在
		return -1;
    
	zipFile newZipFile = zipOpen(zipFileName, APPEND_STATUS_CREATE); //创建zip文件    
	if (newZipFile == NULL)    
	{    
		printf("无法创建zip文件!");    
		return -2;    
	}

	if(FileInfo.attrib & _A_SUBDIR)// is a directory
	{
		AddFileToZip(newZipFile,FileInfo.name,NULL);
		CollectFilesInDirToZip(newZipFile, dirName, FileInfo.name);    
	}
	else// is a file
		AddFileToZip(newZipFile, FileInfo.name, dirName); 
	zipClose(newZipFile, NULL); //关闭zip文件   
	return 0;
}    

cPackFile::cPackFile()
{

}

cPackFile::~cPackFile()
{

}
