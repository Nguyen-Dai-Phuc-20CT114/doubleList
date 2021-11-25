/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream.h>
#include "string.h"
#include "Windows.h"


#include "doubleList_cfg.h"



int main()
{
	/** Khởi tạo một danh sách
	 * ************************************************************
	 * doubleList_t <kiểu_dữ_liệu_t> *tên_danh_sách = create_List <kiểu_dữ_liệu_t>(số_lượng_node, tên_hàm_đặt_dữ_liệu_mỗi_node, chiều)
	**/
	doubleList_t<SinhVien_t> *lopA = create_List<SinhVien_t>(4, set_sinhVien);
	inDanhSachSinhVien("A", lopA, "dung ham tao sinh vien lan dau tien");




	/** Copy một danh sách
	 * ************************************************************
	 * doubleList_t <kiểu_dữ_liệu_t> *tên_danh_sách = copy_List <kiểu_dữ_liệu_t>(danh_sách_gốc, tên_hàm_đặt_dữ_liệu_mỗi_node, chiều)
	**/
	doubleList_t<SinhVien_t> *lopB = copy_List<SinhVien_t>(lopA);
	inDanhSachSinhVien("B", lopB, "dung ham copy danh sach sinh vien lop A");




	/** Sắp xếp một danh sách
	 * ************************************************************
	 * doubleList_t <kiểu_dữ_liệu_t> *tên_danh_sách = copy_List <kiểu_dữ_liệu_t>(danh_sách_gốc, tên_hàm_đặt_dữ_liệu_mỗi_node, chiều)
	**/
	arrange_List(lopB, sttGiamDan);
	inDanhSachSinhVien("B", lopB, "sap xep stt giam dan");

	std::cout << "\n\n";
	
    return 0;
}

