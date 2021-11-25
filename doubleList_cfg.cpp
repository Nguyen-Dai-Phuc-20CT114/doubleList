/** ------------------------------------------------------------
 * Copyright (c) Phuc Nguyen
 * 
 * $Author:             Phuc Nguyen
 * $Date:               November 12, 2021
 * $Version:            2.1.0
 * 
 * File:                doubleList_cfg.cpp
 * Project:             learning data structures
 * -------------------------------------------------------------
 * Brief:
 *      Functions:
 *          1.  Add:        Add a brand new node
 *          2.  Insert:     Insert a existing node
 *          3.  Search:     Search a existing node
 *          4.  Delete:     Delete a existing node
 *          5.  Arrange:    Arrange list
 *          5.  Create:     Create list
**/









/* -----------------------------------------------------------------------------
/* Include libraries
/*
/* -------------------------------------------------------------------------- */

#include "doubleList_cfg.h"









/* -----------------------------------------------------------------------------
/* Gobal variables are used in this file
/*
/* -------------------------------------------------------------------------- */

int soLuongSinhVien = 0;









/* -----------------------------------------------------------------------------
/* Callback function definitions: set data task (functions run when initialize nodes)
/*
/* -------------------------------------------------------------------------- */


void set_sinhVien(SinhVien_t &sinhVien)
{
    soLuongSinhVien += 1;
    sinhVien.set_stt(soLuongSinhVien);
    sinhVien.set_diem(soLuongSinhVien);
}









/* -----------------------------------------------------------------------------
/* Callback function definitions: condition task (functions run when it's true)
/*
/* -------------------------------------------------------------------------- */


bool sttGiamDan(SinhVien_t sinhVien1, SinhVien_t sinhVien2)
{
    // Nếu stt_1 < stt_2 thì thực hiện việc sắp xếp giảm dần
    if(sinhVien1.get_stt() < sinhVien2.get_stt())
    {
        return true;
    }

    // Không thì thôi
    return false;
}









/* -----------------------------------------------------------------------------
/* Callback function definitions: sub task (functions run when traverse list)
/*
/* -------------------------------------------------------------------------- */


void inThongTinSinhVien(SinhVien_t &sinhVien)
{
    std::cout << sinhVien.get_stt() << "\t";
}









/* -----------------------------------------------------------------------------
/* Others function definitions
/*
/* -------------------------------------------------------------------------- */

void inDanhSachSinhVien(std::string lop_s, doubleList_t<SinhVien_t> *lop, std::string hanhDong)
{
    std::cout << "\n\n";

    std::cout << "Danh sach sinh vien lop " << lop_s << " sau khi " << hanhDong << ":\n\t";

    // Đi từ sinh viên đầu tiên tới sinh viên cuối cùng
    // Mỗi lần sang sinh viên mới là thực hiện hàm in thông tin sinh viên một lần
    traverse_List(lop, inThongTinSinhVien);

    std::cout << "\n\n";
}
