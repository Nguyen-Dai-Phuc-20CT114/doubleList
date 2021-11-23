/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream.h>
#include "doubleList.h"
#include "string.h"
#include "Windows.h"

using namespace std;

class sinhVien_t
{
	private:
		static unsigned index;
	public:
		int stt;
		int diem;
		
		sinhVien_t()
		{
			++index;
			stt = diem = index + 1;
		}

		sinhVien_t(bool a)
		{

		}
};
unsigned sinhVien_t::index = 0;





template<class data_t>
void inDSSV(std::string s, doubleNode_t<data_t> *head)
{
	std::cout << "\n\n\n After " << s << " 2 students: ";

	int i = 0;
	doubleNode_t<sinhVien_t> *sv_curr = head;
	while(sv_curr != nullptr)
	{
		std::cout << sv_curr->data_.stt;
		if(sv_curr->get_Next() != nullptr){
			std::cout << " -> ";
		}
		sv_curr = sv_curr->get_Next();
		++i;

		if(i > 21){break;}
	}

	std::cout << "\n";
}


void printSinhVien(sinhVien_t sinhVien)
{
	std::cout << "stt: " << sinhVien.stt << " : " << "diem: " << sinhVien.diem << "\n";
}


bool timSinhVien2(sinhVien_t sinhVien)
{
	if(sinhVien.stt == 2)	{return true;}
	return false;
}

bool sttTangDan(sinhVien_t sinhVien1, sinhVien_t sinhVien2)
{
	if(sinhVien1.stt > sinhVien2.stt)	{return true;}
	return false;
}

bool diem2(sinhVien_t sinhVien)
{
	if(sinhVien.diem == 2){return true;}
	return false;	
}



int main()
{
	
	// doubleNode_t<sinhVien_t> *lopA_head = nullptr;
	// doubleNode_t<sinhVien_t> *lopA_tail = create_List(lopA_head, 4);

	// inDSSV("A create 2 +", lopA_head);

	/* ------------------------------- */

	// std::cout << "\nA get tail: " << get_Tail(lopA_head)->data_.stt << "\n";
	
	// std::cout << "\nA get index: " << get_Index(lopA_head, diem2) << "\n";

	// std::cout << "\nA get node 0: " << get_Node(lopA_head, 0)->data_.stt << "\n";

	// std::cout << "\nA get node 2: " << get_Node(lopA_head, 2)->data_.stt << "\n";

	// std::cout << "\nA find node (student has stt 2): " << get_Node(lopA_head, timSinhVien2, 0)->data_.stt << "\n";
	
	/* ------------------------ */

	// add_Head(lopA_head, 2, STACK);
	// inDSSV("A add head (stack mode)", lopA_head);
	
	// add_Head(lopA_head, 2, QUEUE);
	// inDSSV("A add head (queue mode)", lopA_head);

	/* ------------------------ */

	// add_Tail(lopA_tail, 2);
	// inDSSV("A add tail", lopA_head);

	/* -------------------- */

	// add_Before(lopA_head, 2, 0, QUEUE);
	// inDSSV("A add before (pos 0) (QUEUE)", lopA_head);

	// add_Before(lopA_head, 2, 0, STACK);
	// inDSSV("A add before (pos 0) (STACK)", lopA_head);



	// add_Before(lopA_head, 2, 2, QUEUE);
	// inDSSV("A add before (pos 2) (QUEUE)", lopA_head);

	// add_Before(lopA_head, 2, 2, STACK);
	// inDSSV("A add before (pos 2) (STACK)", lopA_head);



	// add_Before(lopA_head, 2, -1, QUEUE);
	// inDSSV("A add before (pos -1) (QUEUE)", lopA_head);

	// add_Before(lopA_head, 2, -1, STACK);
	// inDSSV("A add before (pos -1) (STACK)", lopA_head);



	// add_Before(lopA_head, 2, 40, QUEUE);
	// inDSSV("A add before (pos 40) (QUEUE)", lopA_head);

	// add_Before(lopA_head, 2, 40, STACK);
	// inDSSV("A add before (pos 40) (STACK)", lopA_head);

	/* ------------------------------- */

	// add_After(lopA_head, lopA_tail, 2, -1);
	// inDSSV("A add after (pos -1)", lopA_head);

	// add_After(lopA_head, lopA_tail, 2, 0);
	// inDSSV("A add after (pos 0)", lopA_head);

	// add_After(lopA_head, lopA_tail, 2, 2);
	// inDSSV("A add after (pos 2)", lopA_head);

	// add_After(lopA_head, lopA_tail, 2, 40);
	// inDSSV("A add after (pos 40)", lopA_head);

	/* ------------------------------- */

	// doubleNode_t<sinhVien_t> *lopB_head = nullptr;
	// doubleNode_t<sinhVien_t> *lopB_tail = create_List(lopB_head, 4);

	// inDSSV("B create 2 +", lopB_head);

	// insert_Head(lopA_head, get_Node(lopB_head, 2));
	// inDSSV("A insert head (B pos 2)", lopA_head);

	// insert_Tail(lopA_tail, get_Node(lopB_head, 2));
	// inDSSV("A insert tail (B pos 2)", lopA_head);


	

	// insert_Before(lopA_head, get_Node(lopB_head, 2), 0);
	// inDSSV("A insert before (A pos 0) (B pos 2)", lopA_head);

	// insert_Before(lopA_head, get_Node(lopB_head, 2), 2);
	// inDSSV("A insert before (A pos 2) (B pos 2)", lopA_head);

	// insert_Before(lopA_head, get_Node(lopB_head, 2), 20);
	// inDSSV("A insert before (A pos 20) (B pos 2)", lopA_head);

	// insert_Before(lopA_head, get_Node(lopB_head, 20), 2);
	// inDSSV("A insert before (A pos 2) (B pos 20)", lopA_head);




	// insert_After(lopA_head, lopA_tail, get_Node(lopB_head, 2), 0);
	// inDSSV("A insert after (A pos 0) (B pos 2)", lopA_head);

	// insert_After(lopA_head, lopA_tail, get_Node(lopB_head, 2), 2);
	// inDSSV("A insert after (A pos 2) (B pos 2)", lopA_head);

	// insert_After(lopA_head, lopA_tail, get_Node(lopB_head, 2), 20);
	// inDSSV("A insert after (A pos 20) (B pos 2)", lopA_head);

	// insert_After(lopA_head, lopA_tail, get_Node(lopB_head, 20), 2);
	// inDSSV("A insert after (A pos 2) (B pos 20)", lopA_head);

	/* ------------------------------- */

	// delete_Head(lopA_head, lopA_tail, 0);
	// inDSSV("A delete head 2 -", lopA_head);

	// delete_Head(lopA_head, lopA_tail, 0);
	// inDSSV("A delete head 2 -", lopA_head);

	// delete_Head(lopA_head, lopA_tail, 2);
	// inDSSV("A delete head", lopA_head);

	// delete_Head(lopA_head, lopA_tail, 20);
	// inDSSV("A delete head 18 +", lopA_head);

	/* ------------------------------- */

	// delete_Tail(lopA_head, lopA_tail, 0);
	// inDSSV("A delete tail 2 -", lopA_head);

	// delete_Tail(lopA_head, lopA_tail, 2);
	// inDSSV("A delete tail", lopA_head);

	// delete_Tail(lopA_head, lopA_tail, 20);
	// inDSSV("A delete tail 18 +", lopA_head);

	/* ------------------------------- */

	// delete_Before(lopA_head, lopA_tail, 0, -1);
	// inDSSV("A delete before (pos -1) 2 -", lopA_head);

	// delete_Before(lopA_head, lopA_tail, 2, -1);
	// inDSSV("A delete before (pos -1)", lopA_head);

	// delete_Before(lopA_head, lopA_tail, 20, -1);
	// inDSSV("A delete before (pos -1) 18 +", lopA_head);



	// delete_Before(lopA_head, lopA_tail, 0, 0);
	// inDSSV("A delete before (pos 0) 2 -", lopA_head);

	// delete_Before(lopA_head, lopA_tail, 2, 0);
	// inDSSV("A delete before (pos 0)", lopA_head);

	// delete_Before(lopA_head, lopA_tail, 20, 0);
	// inDSSV("A delete before (pos 0) 18 +", lopA_head);



	// delete_Before(lopA_head, lopA_tail, 0, 2);
	// inDSSV("A delete before (pos 2) 2 -", lopA_head);

	// delete_Before(lopA_head, lopA_tail, 2, 2);
	// inDSSV("A delete before (pos 2)", lopA_head);

	// delete_Before(lopA_head, lopA_tail, 20, 2);
	// inDSSV("A delete before (pos 2) 18 +", lopA_head);



	// delete_Before(lopA_head, lopA_tail, 0, 20);
	// inDSSV("A delete before (pos 20) 2 -", lopA_head);

	// delete_Before(lopA_head, lopA_tail, 2, 20);
	// inDSSV("A delete before (pos 20)", lopA_head);

	// delete_Before(lopA_head, lopA_tail, 20, 20);
	// inDSSV("A delete before (pos 20) 18 +", lopA_head);

	/* ------------------------------- */

	// delete_After(lopA_head, lopA_tail, 0, -1);
	// inDSSV("A delete after (pos -1) 2 -", lopA_head);

	// delete_After(lopA_head, lopA_tail, 2, -1);
	// inDSSV("A delete after (pos -1)", lopA_head);

	// delete_After(lopA_head, lopA_tail, 20, -1);
	// inDSSV("A delete after (pos -1) 18 +", lopA_head);



	// delete_After(lopA_head, lopA_tail, 0, 0);
	// inDSSV("A delete after (pos 0) 2 -", lopA_head);

	// delete_After(lopA_head, lopA_tail, 2, 0);
	// inDSSV("A delete after (pos 0)", lopA_head);

	// delete_After(lopA_head, lopA_tail, 20, 0);
	// inDSSV("A delete after (pos 0) 18 +", lopA_head);



	// delete_After(lopA_head, lopA_tail, 0, 2);
	// inDSSV("A delete after (pos 2) 2 -", lopA_head);

	// delete_After(lopA_head, lopA_tail, 2, 2);
	// inDSSV("A delete after (pos 2)", lopA_head);

	// delete_After(lopA_head, lopA_tail, 20, 0);
	// inDSSV("A delete after (pos 2) 18 +", lopA_head);



	// delete_After(lopA_head, lopA_tail, 0, 20);
	// inDSSV("A delete after (pos 20) 2 -", lopA_head);

	// delete_After(lopA_head, lopA_tail, 2, 20);
	// inDSSV("A delete after (pos 20)", lopA_head);

	// delete_After(lopA_head, lopA_tail, 20, 20);
	// inDSSV("A delete after (pos 20) 18 +", lopA_head);

	/* ------------------------------- */

	// delete_Node(lopA_head, lopA_tail, 0, -1);
	// inDSSV("A delete node (pos -1) 2 -", lopA_head);

	// delete_Node(lopA_head, lopA_tail, 2, -1);
	// inDSSV("A delete node (pos -1)", lopA_head);

	// delete_Node(lopA_head, lopA_tail, 20, -1);
	// inDSSV("A delete node (pos -1) 18 +", lopA_head);



	// delete_Node(lopA_head, lopA_tail, 0, 0);
	// inDSSV("A delete node (pos 0) 2 -", lopA_head);

	// delete_Node(lopA_head, lopA_tail, 2, 0);
	// inDSSV("A delete node (pos 0)", lopA_head);

	// delete_Node(lopA_head, lopA_tail, 20, 0);
	// inDSSV("A delete node (pos 0) 18 +", lopA_head);



	// delete_Node(lopA_head, lopA_tail, 0, 2);
	// inDSSV("A delete node (pos 2) 2 -", lopA_head);

	// delete_Node(lopA_head, lopA_tail, 2, 2);
	// inDSSV("A delete node (pos 2)", lopA_head);

	// delete_Node(lopA_head, lopA_tail, 20, 2);
	// inDSSV("A delete node (pos 2) 18 +", lopA_head);



	// delete_Node(lopA_head, lopA_tail, 0, 20);
	// inDSSV("A delete node (pos 20) 2 -", lopA_head);

	// delete_Node(lopA_head, lopA_tail, 2, 20);
	// inDSSV("A delete node (pos 20)", lopA_head);

	// delete_Node(lopA_head, lopA_tail, 20, 20);
	// inDSSV("A delete node (pos 20) 18 +", lopA_head);

	/* ------------------------------- */

	// delete_All(lopA_head, lopA_tail);
	// inDSSV("A delete all", lopA_head);

	/* ------------------------------- */

	// arrange_List(lopA_head, sttTangDan);
	// inDSSV("A arrange list", lopA_head);


	std::cout << "\n\n";
	
    return 0;
}

