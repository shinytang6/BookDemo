//
// Created by liuyubobobo on 8/28/16.
//


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

// �ļ���ز���
namespace FileOps{

    // ��ȡ�ļ�����Ϊfilename�е����ݣ��������а��������д���Ž�words��
    int firstCharacterIndex(const string& s, int start){
        for( int i = start ; i < s.length() ; i ++ )
            if( isalpha(s[i]) )
                return i;
        return s.length();
    }

    // ���ַ���s�е�������ĸת����Сд֮�󷵻�
    string lowerS( const string& s){

        string ret = "";
        for( int i = 0 ; i < s.length() ; i ++ )
            ret += tolower(s[i]);
        return ret;
    }

    // ��ȡ�ļ�����Ϊfilename�е����ݣ��������а��������д���Ž�words��
    bool readFile(const string& filename, vector<string> &words){

        // �ļ���ȡ
        string line;
        string contents = "";
        ifstream file(filename);
        if( file.is_open() ){
            while( getline(file, line))
                contents += ( line + "\n" );
            file.close();
        }
        else{
            cout<<"Can not open "<<filename<<" !!!"<<endl;
            return false;
        }

        // �򵥷ִ�
        // ����ִʷ�ʽ��Լ�ª, û�п��Ǻܶ��ı������е���������
        // ������ֻ��demoչʾ��
        int start = firstCharacterIndex(contents, 0);
        for( int i = start + 1 ; i <= contents.length() ; )
            if( i == contents.length() || !isalpha(contents[i]) ){
                words.push_back( lowerS( contents.substr(start,i-start) ) );
                start = firstCharacterIndex(contents, i);
                i = start + 1;
            }
            else
                i ++;

        return true;
    }

}
