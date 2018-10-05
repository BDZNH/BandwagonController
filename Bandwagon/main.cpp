#include<iostream>


#include<curl/curl.h>
#include <nlohmann/json.hpp>
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
	std::cin >> id >> key;
	con1.setVPSID(id);
	con1.setVPSKey(key);
	con1.getVPSInfo(info,httpcode);
	if (200 == httpcode || 201 == httpcode)
	{
		//nlohmann::json j1(info);
		////std::cout << info << std::endl;
		//std::cout << j1 << std::endl;
		std::string::iterator itor;
		for (itor = info.begin(); itor != info.end(); itor++)
		{
			if ('{' == *itor)
			{
				std::cout << '{' << std::endl;
			}
			else if ((',' == *itor)&&('\"'==*(itor+1)))
			{
				std::cout << ',' << std::endl;
			}
			else if ('}' == *itor)
			{
				std::cout << std::endl << '}' << std::endl;
				continue;
			}
			else
			{
				std::cout << *itor;
			}
		}
	}
	
	return 0;
}
