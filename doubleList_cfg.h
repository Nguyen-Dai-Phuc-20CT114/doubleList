/** ------------------------------------------------------------
 * Copyright (c) Phuc Nguyen
 * 
 * $Author:             Phuc Nguyen
 * $Date:               November 12, 2021
 * $Version:            2.1.0
 * 
 * File:                doubleList_cfg.h
 * Project:             learning data structures
 * -------------------------------------------------------------
 * Brief:
 *      This file includes 
 *          - data type
 *          - callback function prototypes
 *          - others function prototypes
 * 
 *      is used in file main_doubleList.cpp
**/

#ifndef DOUBLELIST_CFG_H
#define DOUBLELIST_CFG_H









/* -----------------------------------------------------------------------------
/* Include libraries
/*
/* -------------------------------------------------------------------------- */
#include <iostream.h>
#include <string.h>

#include "doubleList.h"









/* -----------------------------------------------------------------------------
/* Data types for double list 
/*
/* -------------------------------------------------------------------------- */


class SinhVien_t
{
    /*** Variables ***/
    public:
        int stt_;
        int diem_;
    
    /*** Contructors ***/
    public:
        SinhVien_t(){}

    /*** Get functions ***/
    public:
        int get_stt() {return stt_; }
        int get_diem(){return diem_;}

    /*** Set functions ***/
    public:
        void set_stt(int stt)   {stt_ = stt;}
        void set_diem(int diem) {diem_ = diem;}
};









/* -----------------------------------------------------------------------------
/* Callback function protocol: set data task (functions run when initialize nodes)
/*
/* -------------------------------------------------------------------------- */


void set_sinhVien(SinhVien_t &sinhVien);









/* -----------------------------------------------------------------------------
/* Callback function protocol: condition task (functions run when it's true)
/*
/* -------------------------------------------------------------------------- */


bool sttGiamDan(SinhVien_t sinhVien1, SinhVien_t sinhVien2);









/* -----------------------------------------------------------------------------
/* Callback function protocol: sub task (functions run when traverse list)
/*
/* -------------------------------------------------------------------------- */

void inThongTinSinhVien(SinhVien_t &sinhVien);









/* -----------------------------------------------------------------------------
/* Others function protocols
/*
/* -------------------------------------------------------------------------- */

void inDanhSachSinhVien(std::string lop_s, doubleList_t<SinhVien_t> *lop, std::string hanhDong);





#endif // DOUBLELIST_CFG_H
