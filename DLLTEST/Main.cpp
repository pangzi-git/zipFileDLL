#include <stdlib.h>
#include <stdio.h>
#include "../ZipFileDLL/Define.h"

typedef  BOOL (*Zip) (void *pLog,const char *LocalPath,const char * pFileName); 

typedef  BOOL (*UnZip      )(void *pLog,const char *LocalPath,const char * pFileName); 
int main(int argc, char ** argv)
{
	Zip       zip     ;
	UnZip     unzip     ;
    ACE_DLL    dll;
    //定义变量
    int retval = dll.open("../Debug/ZipFileDLL.dll",ACE_DEFAULT_SHLIB_MODE,1);
    zip      =(Zip            )dll.symbol("Zip"      );  
	unzip      =(UnZip            )dll.symbol("UnZip"      );  
	unzip(NULL,"c:\\download\\","20110607160738.data.zip");
    dll.close();
	return 0;
}