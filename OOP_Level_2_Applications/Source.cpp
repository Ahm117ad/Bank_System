#pragma warning(disable : 4996) 

#include<iostream>
#include"clsLoginScreen.h"


using namespace std;



int main()
{

	clsUtil::Srand();

	while (true)
	{
		if (!clsLoginScreen::ShhowLoginScreen())
		{
			break;
		}
	}
	
	system("pause>0");
 	return 0;
}
