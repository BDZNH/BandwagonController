#include<iostream>


#include<curl/curl.h>
#include"BandwagonController.h"


#ifdef _DEBUG
#pragma comment(lib,"libcurld.lib")
#else
#pragma comment(lib,"libcurl.lib")
#endif // !_DEBUG

int main()
{

	BandwagonController con1;
	std::string info,id,key;
	int httpcode;
	//char *ct;
	std::cin >> id >> key;
	con1.setVPSID(id);
	con1.setVPSKey(key);
	con1.getVPSInfo(info,httpcode);
	if (200 == httpcode || 201 == httpcode)
	{
		std::cout << info << std::endl;
	}
	
	return 0;
}
