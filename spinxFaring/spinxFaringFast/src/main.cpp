// =============================================================================
// SpinYForm is for spintransformation-based fairing
// that is based on combination of DDG and spinxform by Keenan Crane
// Ryo Yamada
// Feburuary 18, 2017
// main.cpp
//

#include <iostream>
#include <sstream>
#include <fstream>

#include "MeshY.h"
#include "Application.h"



using namespace std;
using namespace DDG;

// argv[1] : obj�t�@�C�����B���ʓ����I�u�W�F�N�g��obj�t�@�C��
// argv[2] : Fairing�����̂P�X�e�b�v�ł̕��A0.9�Ƃ����̂́A�ȗ���10%�ω������ĕ��R������A�ƌ����Ӗ�
// argv[3] : �X�e�b�v��
// argv[4] : �o�̓t�@�C�����̍� hoge�Ǝw�肷��� hoge0.obj,hoge1.obj,..�Ƃ������O�̃t�@�C�����ł���
// ./fairing hogei.obj�Ƃ���΂݂���
int main( int argc, char **argv )
{

   int n = atoi( argv[3] ); //��3�����𐮐��^�ɕϊ�����n�ɑ��
   double step = atof( argv[2] ); //��2�����������^�ɕϊ�����x�ɑ��
   // load mesh
   spiny::Mesh meshY;
   meshY.read( argv[1] ); //��1������obj�t�@�C����
   
   // processing with Application.h
   
   Application app;
   for(int i=0;i<n;i++){
     app.process(step,meshY);
     std::ostringstream os;
     os << argv[4] << i << ".obj";
     std::string name=os.str();
     meshY.write(name);
   }
   

   return 0;
}
