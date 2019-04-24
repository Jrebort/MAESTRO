#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <string.h>

using namespace std;

/*char to str*/
string charToStr(char * contentChar)
{
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}
 
void modifyContentInFile(char *fileName,int lineNum,char *content)
{
	ifstream in;
	char line[1024]={'\0'};
	in.open(fileName);

	int i=0;
	string tempStr;

	while(in.getline(line,sizeof(line)))
	{	

		i++;
		if(lineNum!=i)
		{	
			tempStr+=charToStr(line);
		}
		else
		{
	       tempStr+=charToStr(content);
		}
		tempStr+='\n';
	}
	in.close();
	ofstream out;
	out.open(fileName);
	out.flush();
	out<<tempStr;
//	cout << tempStr << "";
	out.close();
 }
 
int main()
{	
	FILE *fp;
	char config_name[]="./data/layer/layer_configuration.m";
	const char *content_item;
	vector <string> content_buffer;
	vector <string>::iterator iter;
	int lineNum=6;
	char cmd[]="./maestro --dataflow_file='data/dataflow/rs.m' \
	         --layer_file='data/layer/layer_configuration.m' \
	         --noc_bw=4 \
	         --num_pes=16";
	
	fp = fopen("./data/layer/layer_configuration.m","r+");
	if (fp ==NULL){
		printf("%s\n","fail to open the file of layer_configuration");
	}

//modify x:shape of input feature
	int x=32;
	while(x<=224){
		content_buffer.push_back("X "+ std::to_string(x));
		x++;
	}

	for(auto &node:content_buffer){
    content_item = node.c_str();
    char *content_item2 = (char*)content_item;
//    cout << content_item2 <<endl;
    modifyContentInFile(config_name,lineNum,content_item2);
    system(cmd);
    
//  call python script

	}
	return 0;
}