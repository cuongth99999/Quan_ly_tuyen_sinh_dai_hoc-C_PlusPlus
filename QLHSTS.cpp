/*
Nhom 7 - Quan ly ho so tuyen sinh dai hoc
- Nguyen Quang Ha (2110A03)
- Nguyen Van Dung (2110A03)
- Ta Huu Cuong    (2110A03)
*/

#include <bits/stdc++.h>

using namespace std;
FILE* file;

struct Nganh
{
    char sMaNganh[100] = "NULL";
    char sTenNganh[100] = "NULL";
    float fDiemChuan = 0;
    int iSoLuongTuyenSinh = 0;
};

struct Khoa
{
    char sMaKhoa[100] = "NULL";
    char sTenKhoa[100] = "NULL";
    char sDiaChi[100] = "NULL";
    int iSoLuongNganh = 0;
    Nganh DSNganh[20];
};

struct SinhVien
{
    char sMaSV[100] = "NULL";
    char sSoThuTu[100] = "NULL";
    char sTenSV[100] = "NULL";
    char sNgaySinh[100] = "NULL";
    char sThanhPho[100] = "NULL";
    char sKhuVuc[100] = "NULL";
    char sGioiTinh[100] = "NULL";
    char sSDT[100] = "NULL";
    char NganhDangKy[20][100];
    float fDiemCong = 0.0f;
    float fDiemMon1 = 0.0f;
    float fDiemMon2 = 0.0f;
    float fDiemMon3 = 0.0f;
    float fTongDiem = 0.0f;
    int iSoLuongNganhDangKy = 0;
    int iSoNVTuyenThang = 0;
};

struct QuanLyHoSo
{
    SinhVien sinhVien;
};

struct NodeQuanLyHoSo
{
    QuanLyHoSo info;
    struct NodeQuanLyHoSo* next = NULL;
};

struct DanhSachQuanLyHoSo
{
    NodeQuanLyHoSo* Head;
    NodeQuanLyHoSo* Tail;
};

DanhSachQuanLyHoSo QLHSTS;

struct QuanLyKhoa
{
    Khoa khoa;
};

struct DoubleNodeQuanLyKhoa
{
    QuanLyKhoa info;
    struct DoubleNodeQuanLyKhoa* next = NULL;
    struct DoubleNodeQuanLyKhoa* previous = NULL;
};

struct DoubleDanhSachQuanLyKhoa
{
    DoubleNodeQuanLyKhoa* Head;
    DoubleNodeQuanLyKhoa* Tail;
};

DoubleDanhSachQuanLyKhoa QLK;

void TieuDeKhoa ()
{
    cout << endl << setw(5) << setiosflags(ios::left) << "STT";
	cout << setw(15) << "Ma khoa";
	cout << setw(30) << "Ten khoa";
	cout << setw(20) << "Dia chi";
}

void HienNganh(Nganh a) {
	cout << "- Ma nganh: " << a.sMaNganh << endl;
	cout << "- Ten nganh: " << a.sTenNganh << endl;
	cout << "- Diem chuan: " << a.fDiemChuan << endl;
	cout << "- So luong tuyen: " << a.iSoLuongTuyenSinh << endl;
	cout << endl;
}

void NhapKhoa (Khoa& a, bool& inputAble) {
    DoubleNodeQuanLyKhoa* dq;
    DoubleDanhSachQuanLyKhoa DQ = QLK;

    cin.ignore();
    cout << "Nhap ma khoa: "; cin.getline(a.sMaKhoa, 100);
    for (dq = DQ.Head; dq != NULL; dq = dq->next) {
        if (strcmp(dq->info.khoa.sMaKhoa, a.sMaKhoa) == 0) {
            cout << "\nMa khoa da ton tai!";
            inputAble = false;
            return;
        }
    }

    cout << "Nhap ten khoa: "; cin.getline(a.sTenKhoa, 100);
	cout << "Nhap dia chi: "; cin.getline(a.sDiaChi, 100);
	cout << "Nhap so luong Nganh: "; cin >> a.iSoLuongNganh;
    cin.ignore();
    for (int i = 0; i < a.iSoLuongNganh; i++) {
        cout << "Nganh thu " << i + 1 << ": \n";
		cout << "- Nhap ma nganh: "; cin.getline(a.DSNganh[i].sMaNganh, 100);
		cout << "- Nhap ten nganh: "; cin.getline(a.DSNganh[i].sTenNganh, 100);
		cout << "- Nhap diem chuan: "; cin >> a.DSNganh[i].fDiemChuan;
		cout << "- Nhap so luong tuyen sinh: "; cin >> a.DSNganh[i].iSoLuongTuyenSinh;
		cin.ignore();
    }
}

void HienKhoa(Khoa a) {
	TieuDeKhoa();
	cout << endl << setw(1) << setiosflags(ios::left) << "+)   ";
	cout << setw(15) << a.sMaKhoa;
	cout << setw(30) << a.sTenKhoa;
	cout << setw(20) << a.sDiaChi;
	cout << endl;
	cout << "\n(Cac nganh cua khoa " << a.sTenKhoa << ")\n" << endl;
	for (int i = 0; i < a.iSoLuongNganh; i++)
	{
		cout << "- Ma nganh: " << a.DSNganh[i].sMaNganh << endl;
		cout << "- Ten nganh: " << a.DSNganh[i].sTenNganh << endl;
		cout << "- Diem chuan: " << a.DSNganh[i].fDiemChuan << endl;
		cout << "- So luong tuyen: " << a.DSNganh[i].iSoLuongTuyenSinh << endl;
		cout << endl;
	}
}

void TieuDeSinhVien()
{
	cout << endl << setw(0) << setiosflags(ios::left);
	cout << setw(8) << "Ma SV";
	cout << setw(10) << "So TT";
	cout << setw(20) << "Ten SV";
	cout << setw(15) << "Ngay sinh";
	cout << setw(15) << "Thanh pho";
	cout << setw(8) << "Khu vuc";
	cout << setw(9) << "Gender";
	cout << setw(15) << "PhoneNumber";
	cout << setw(12) << "Tong diem";
	cout << setw(12) << "So NV tuyen thang";
}

float DiemCong (string khuVuc)
{
    float cong = 0.0f;
    if (khuVuc == "KV01")
		cong = 0.75f;
	else if (khuVuc == "KV02")
		cong = 0.5f;
	else if (khuVuc == "KV03")
		cong = 0.25f;
	else if (khuVuc == "KV04")
		cong = 0.0f;
	return cong;
}

/*void NhapSinhVien (SinhVien& a, bool& inputAble) {
    inputAble = true;
    NodeQuanLyHoSo* p;
    DoubleNodeQuanLyKhoa* dq;
    DanhSachQuanLyHoSo Q = QLHSTS;
    DoubleDanhSachQuanLyKhoa DQ = QLK;

    cin.ignore();
    cout << "Nhap ma sinh vien: "; cin.getline(a.sMaSV, 100);
    for (p = Q.Head; p != NULL; p = p->next) {
        if (strcmp(p->info.sinhVien.sMaSV, a.sMaSV) == 0) {
            cout << "\nMa sinh vien da ton tai!";
            inputAble = false;
            return;
        }
    }
    cout << "Nhap so thu tu: "; cin.getline(a.sSoThuTu, 100);
    cout << "Nhap ten sinh vien: "; cin.getline(a.sTenSV, 100);
	cout << "Nhap ngay sinh: "; cin.getline(a.sNgaySinh, 100);
	cout << "Nhap thanh pho: "; cin.getline(a.sThanhPho, 100);
	cout << "Nhap khu vuc (KV__): "; cin.getline(a.sKhuVuc, 100);
	string khuVuc = a.sKhuVuc;
	if (khuVuc != "KV01" && khuVuc != "KV02" && khuVuc != "KV03" && khuVuc != "KV04") {
		cout << "\nKhu vuc khong hop le!";
		inputAble = false;
		return;
	}

	cout << "Nhap gioi tinh: "; cin.getline(a.sGioiTinh, 100);
	cout << "Nhap so dien thoai: "; cin.getline(a.sSDT, 100);

	cout << "\n---Danh sach Ma nganh va Ten nganh---\n";
	for (dq = DQ.Head; dq != NULL; dq = dq->next) {
		for (int i = 0; i < dq->info.khoa.iSoLuongNganh; i++) {
			cout << dq->info.khoa.DSNganh[i].sMaNganh << " - " << dq->info.khoa.DSNganh[i].sTenNganh << endl;
		}
	}

	cout << "\nNhap so nganh dang ky: ", cin >> a.iSoLuongNganhDangKy;
    fflush(stdin);
    //Kiểm tra ngành đã nhập để xem nó có tồn tại không
    for (int i = 0; i < a.iSoLuongNganhDangKy; i++) {
        //bool isExisted = false;
        cout << "Nhap nganh thu " << i + 1 << " (Chi nhap nhung nganh cho phep): ";
        cin.getline(a.NganhDangKy[i], 100);
        fflush(stdin);
        //string h1 = a.NganhDangKy[i];

        /*for (dq = DQ.Head; dq != NULL; dq->next) {
            for (int i = 0; i < dq->info.khoa.iSoLuongNganh; i++) {
                string h2 = dq->info.khoa.DSNganh[i].sMaNganh;
                if (h1 == h2) {
                    isExisted = true;
                    break;
                }
            }
            if (isExisted) {
                break;
            }
        }
        if (!isExisted) {
            cout << "\nMa nganh dang ky khong hop le!";
			inputAble = false;
			return;
        }
    }

    /*a.fDiemCong = DiemCong(a.sKhuVuc);
	cout << "Nhap diem mon 1: "; cin >> a.fDiemMon1;
	cout << "Nhap diem mon 2: "; cin >> a.fDiemMon2;
	cout << "Nhap diem mon 3: "; cin >> a.fDiemMon3;
	a.fTongDiem = a.fDiemMon1 + a.fDiemMon2 + a.fDiemMon3 + a.fDiemCong;
}*/

void NhapSinhVien (SinhVien& a, bool& inputAble) {
    inputAble = true;
    NodeQuanLyHoSo* p;
    DoubleNodeQuanLyKhoa* dq;
    DanhSachQuanLyHoSo Q = QLHSTS;
    DoubleDanhSachQuanLyKhoa DQ = QLK;

    cin.ignore();
    cout << "Nhap ma sinh vien: "; cin.getline(a.sMaSV, 100);
    for (p = Q.Head; p != NULL; p = p->next) {
        if (strcmp(p->info.sinhVien.sMaSV, a.sMaSV) == 0) {
            cout << "\nMa sinh vien da ton tai!";
            inputAble = false;
            return;
        }
    }
    cout << "Nhap so thu tu: "; cin.getline(a.sSoThuTu, 100);
    cout << "Nhap ten sinh vien: "; cin.getline(a.sTenSV, 100);
	cout << "Nhap ngay sinh: "; cin.getline(a.sNgaySinh, 100);
	cout << "Nhap thanh pho: "; cin.getline(a.sThanhPho, 100);
	cout << "Nhap khu vuc (KV__): "; cin.getline(a.sKhuVuc, 100);
	string khuVuc = a.sKhuVuc;
	if (khuVuc != "KV01" && khuVuc != "KV02" && khuVuc != "KV03" && khuVuc != "KV04") {
		cout << "\nKhu vuc khong hop le!";
		inputAble = false;
		return;
	}

	cout << "Nhap gioi tinh: "; cin.getline(a.sGioiTinh, 100);
	cout << "Nhap so dien thoai: "; cin.getline(a.sSDT, 100);

	cout << "\n---Danh sach Ma nganh va Ten nganh---\n";
	for (dq = DQ.Head; dq != NULL; dq = dq->next) {
		for (int i = 0; i < dq->info.khoa.iSoLuongNganh; i++) {
			cout << dq->info.khoa.DSNganh[i].sMaNganh << " - " << dq->info.khoa.DSNganh[i].sTenNganh << endl;
		}
	}

	cout << "\nNhap so nganh dang ky: ", cin >> a.iSoLuongNganhDangKy;
    fflush(stdin);
    //Kiểm tra ngành đã nhập để xem nó có tồn tại không
    for (int i = 0; i < a.iSoLuongNganhDangKy; i++) {
        //bool isExisted = false;
        cout << "Nhap nganh thu " << i + 1 << " (Chi nhap nhung nganh cho phep): ";
        cin.getline(a.NganhDangKy[i], 100);
        fflush(stdin);
    }

    a.fDiemCong = DiemCong(a.sKhuVuc);
	cout << "Nhap diem mon 1: "; cin >> a.fDiemMon1;
	cout << "Nhap diem mon 2: "; cin >> a.fDiemMon2;
	cout << "Nhap diem mon 3: "; cin >> a.fDiemMon3;
	a.fTongDiem = a.fDiemMon1 + a.fDiemMon2 + a.fDiemMon3 + a.fDiemCong;
	cout << endl;
	cout << "Nhap so nguyen vong tuyen thang: "; cin >> a.iSoNVTuyenThang;
}


void HienSinhVien (SinhVien a) {
	cout << endl << setw(0) << setiosflags(ios::left);
	cout << setw(8) << a.sMaSV;
	cout << setw(10) << a.sSoThuTu;
	cout << setw(20) << a.sTenSV;
	cout << setw(15) << a.sNgaySinh;
	cout << setw(15) << a.sThanhPho;
	cout << setw(8) << a.sKhuVuc;
	cout << setw(9) << a.sGioiTinh;
	cout << setw(15) << a.sSDT;
	cout << setw(12) << a.fTongDiem;
	cout << setw(12) << a.iSoNVTuyenThang;
}

void HienNganhDangKy (SinhVien a) {
	cout << "\n(DS Nganh cua ho so SV" << a.sMaSV << " dang ky)\n";
	for (int i = 0; i < a.iSoLuongNganhDangKy; i++)
		cout << "- Ma nganh thu " << i + 1 << " : " << a.NganhDangKy[i] << endl;
}

// =================================================================================== NODE SYSTEM FOR PROFILES
void KhoiTaoDSQuanLyHoSo (DanhSachQuanLyHoSo& Q) {
    Q.Head = NULL;
    Q.Tail = NULL;
}

void SwapNode(NodeQuanLyHoSo* p, NodeQuanLyHoSo* q) {
	QuanLyHoSo temp;
	temp = p->info;
	p->info = q->info;
	q->info = temp;
}

NodeQuanLyHoSo* GetNodeQLHSTS(QuanLyHoSo x) {
    NodeQuanLyHoSo* p;
    p = new NodeQuanLyHoSo();
    if (p == NULL) {
        cout << "\nKhoi tao Node khong thanh cong!";
        exit(0);
    }
    p->info = x;
    p->next = NULL;
    return p;
}

NodeQuanLyHoSo* TimKiemHoSoTheoMaSV(DanhSachQuanLyHoSo Q, string h) {
	NodeQuanLyHoSo* p;
	for (p = Q.Head; p != NULL; p = p->next) {
		if (p->info.sinhVien.sMaSV == h)
			return p;
	}
	return p;
}

void ChenDauDSQLHoSo(DanhSachQuanLyHoSo& Q, NodeQuanLyHoSo* p) {
	if (Q.Head == NULL) {
		Q.Head = p;
		Q.Tail = p;
	}
	else
	{
		p->next = Q.Head;
		Q.Head = p;
	}
}

void ChenCuoiDSQLHoSo(DanhSachQuanLyHoSo& Q, NodeQuanLyHoSo* p) {
	if (Q.Head == NULL) {
		Q.Head = p;
		Q.Tail = p;
	}
	else
	{
		Q.Tail->next = p;
		Q.Tail = p;
	}
}

// =================================================================================== NODE SYSTEM FOR FACULTIES
void KhoiTaoDSQuanLyKhoa(DoubleDanhSachQuanLyKhoa& DQ) {
	DQ.Head = NULL;
	DQ.Tail = NULL;
}

void SwapDoubleNode(DoubleNodeQuanLyKhoa* p, DoubleNodeQuanLyKhoa* q) {
	QuanLyKhoa temp;
	temp = p->info;
	p->info = q->info;
	q->info = temp;
}

DoubleNodeQuanLyKhoa* GetDoubleNodeQLK(QuanLyKhoa x) {
	DoubleNodeQuanLyKhoa* p;
	p = new DoubleNodeQuanLyKhoa();
	if (p == NULL) {
		cout << "\nKhoi tao Node khong thanh cong!";
		exit(0);
	}
	p->info = x;
	p->next = NULL;
	p->previous = NULL;
	return p;
}

DoubleNodeQuanLyKhoa* TimKiemKhoaTheoMaKhoa(DoubleDanhSachQuanLyKhoa DQ, string h) {
	DoubleNodeQuanLyKhoa* p;
	for (p = DQ.Head; p != NULL; p = p->next) {
		if (p->info.khoa.sMaKhoa == h)
			return p;
	}
	return p;
}

void ChenDauDSQLKhoa (DoubleDanhSachQuanLyKhoa& DQ, DoubleNodeQuanLyKhoa* p) {
	if (DQ.Head == NULL) {
		DQ.Head = p;
		DQ.Tail = p;
	}
	else
	{
		p->next = DQ.Head;
		DQ.Head->previous = p;
		DQ.Head = p;
	}
}

void ChenCuoiDSQLKhoa(DoubleDanhSachQuanLyKhoa& DQ, DoubleNodeQuanLyKhoa* p) {
	if (DQ.Head == NULL) {
		DQ.Head = p;
		DQ.Tail = p;
	}
	else
	{
		DQ.Tail->next = p;
		p->previous = DQ.Tail;
		DQ.Tail = p;
	}
}

// =================================================================================== FUNCTIONS IN MENU OPTIONS
// OPTION 1: Nhập thông tin vào danh sách
void NhapDanhSachQLHSTS(DanhSachQuanLyHoSo& Q) {
	NodeQuanLyHoSo* p;
	QuanLyHoSo x;
	cout << "\n=== NHAP DS QUAN LY HO SO ===\n";
	bool check = true;
	NhapSinhVien(x.sinhVien, check);
	if (check) {
		cout << "\nInput Successfully!";
		p = GetNodeQLHSTS(x);
		ChenDauDSQLHoSo(Q, p);
	}
}

// OPTION 2: Nhập danh sách quản lý khoa
void NhapDanhSachQLKhoa(DoubleDanhSachQuanLyKhoa& DQ) {
	DoubleNodeQuanLyKhoa* p;
	QuanLyKhoa x;
	cout << "\n=== NHAP DS QUAN LY KHOA ===\n";
	bool check = true;
	NhapKhoa(x.khoa, check);
	if (check) {
		cout << "\nInput Successfully!";
		p = GetDoubleNodeQLK(x);
		ChenDauDSQLKhoa(DQ, p);
	}
}

// OPTION 3: Show DS QLHS
void HienDSQLHoSo(DanhSachQuanLyHoSo& Q) {
	NodeQuanLyHoSo* p;
	cout << "\n=== PROFILE INFOMATION ===\n";
	TieuDeSinhVien();
	for (p = Q.Head; p != NULL; p = p->next) {
		HienSinhVien(p->info.sinhVien);
	}
	cout << "\n\n==========================================\n";
	for (p = Q.Head; p != NULL; p = p->next) {
		HienNganhDangKy(p->info.sinhVien);
	}
}

// OPTION 4: Show Ngành và Khoa
void HienDSQlKhoa(DoubleDanhSachQuanLyKhoa& DQ) {
	DoubleNodeQuanLyKhoa* p;
	cout << "\n=== FACULTY INFOMATION ===\n";
	for (p = DQ.Head; p != NULL; p = p->next) {
		HienKhoa(p->info.khoa);
	}
}

// OPTION 5: Sắp xếp DS hồ sơ theo tổng điểm giảm dần (DESC)
void SortTongDiemDESC(DanhSachQuanLyHoSo& Q) {
	NodeQuanLyHoSo* p, * q;
	QuanLyHoSo temp;
	for (p = Q.Head; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next)
			if (p->info.sinhVien.fTongDiem < q->info.sinhVien.fTongDiem) {
				SwapNode(p, q);
			}
	}
	cout << "\nSap xep giam dan thanh cong!";
}

// OPTION 6: Sắp xếp DS hồ sơ theo tổng điểm tăng dần (ASC)
void SortTongDiemASC(DanhSachQuanLyHoSo& Q) {
	NodeQuanLyHoSo* p, * q;
	QuanLyHoSo temp;
	for (p = Q.Head; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next)
			if (p->info.sinhVien.fTongDiem > q->info.sinhVien.fTongDiem) {
				SwapNode(p, q);
			}
	}
	cout << "\nSap xep tang dan thanh cong!";
}

// OPTION 7: Tìm kiếm hồ sơ theo mã hồ sơ
void TimKiemHoSoTheoMaStringH(DanhSachQuanLyHoSo& Q) {
	string h;
	cin.ignore();
	cout << "\nNhap ma ho so can tim kiem: "; getline(cin, h);

	NodeQuanLyHoSo* p;
	p = TimKiemHoSoTheoMaSV(Q, h);

	if (p == NULL)
		cout << "\nMa ho so khong hop le!\n";
	else
		for (p = Q.Head; p != NULL; p = p->next) {
			if (p->info.sinhVien.sMaSV == h)
			{
				TieuDeSinhVien();
				HienSinhVien(p->info.sinhVien);
			}

		}
}

// OPTION 8: Delete First Profile
void RemoveHead(DanhSachQuanLyHoSo& Q) {
	NodeQuanLyHoSo* p;
	if (Q.Head != NULL) {
		p = Q.Head;
		Q.Head = Q.Head->next;
		delete p;
		if (Q.Head == NULL)
			Q.Tail = NULL;
	}
	cout << "Xoa ho so thanh cong!";
}

// OPTION 9: Tìm kiếm hồ sơ tổng điểm Max
void TimHoSoDiemMax(DanhSachQuanLyHoSo Q) {
	NodeQuanLyHoSo* p;

	float max = Q.Head->info.sinhVien.fTongDiem;
	p = Q.Head;
	while (p != NULL) {
		if (p->info.sinhVien.fTongDiem > max) {
			max = p->info.sinhVien.fTongDiem;
		}
		p = p->next;
	}
	TieuDeSinhVien();
	for (p = Q.Head; p != NULL; p = p->next) {
		if (p->info.sinhVien.fTongDiem == max)
			HienSinhVien(p->info.sinhVien);
	}
}

// OPTION 10: Tìm kiếm hồ sơ tổng điểm Min
void TimHoSoDiemMin(DanhSachQuanLyHoSo Q)
{
	NodeQuanLyHoSo* p;

	float min = Q.Head->info.sinhVien.fTongDiem;
	p = Q.Head;
	while (p != NULL) {
		if (p->info.sinhVien.fTongDiem < min)
		{
			min = p->info.sinhVien.fTongDiem;
		}
		p = p->next;
	}
	TieuDeSinhVien();
	for (p = Q.Head; p != NULL; p = p->next)
	{
		if (p->info.sinhVien.fTongDiem == min)
			HienSinhVien(p->info.sinhVien);
	}
}

// OPTION 11: Lưu DSHSTS vào File .dat
void SaveFile(DanhSachQuanLyHoSo Q) {
	FILE* f;
	f = fopen("ProfileList.dat", "wb");
	int n = 0;
	NodeQuanLyHoSo* p;

	for (p = Q.Head; p != NULL; p = p->next)
		n++;
	fwrite(&n, sizeof(int), 1, f);

	for (p = Q.Head; p != NULL; p = p->next)
		fwrite(&p->info, sizeof(QuanLyHoSo), 1, f);
	fclose(f);
	cout << "\nSuccessfully Saved File!";
}

// OPTION 12: Lưu DSQLKhoa vào File .dat
void SaveFileFaculty(DoubleDanhSachQuanLyKhoa DQ) {
	FILE* f;
	f = fopen("FacultyList.dat", "wb");
	int n = 0;
	DoubleNodeQuanLyKhoa* p;

	for (p = DQ.Head; p != NULL; p = p->next)
		n++;
	fwrite(&n, sizeof(int), 1, f);

	for (p = DQ.Head; p != NULL; p = p->next)
		fwrite(&p->info, sizeof(QuanLyKhoa), 1, f);
	fclose(f);
	cout << "\nSuccessfully Saved File!";
}

// OPTION 13: Đọc DSQLKHSTS từ File
void ReadFile(DanhSachQuanLyHoSo& Q) {
	FILE* f;
	QuanLyHoSo x;
	int i, n;
	NodeQuanLyHoSo* p;

	f = fopen("ProfileList.dat", "rb");
	fread(&n, sizeof(int), 1, f);

	for (i = 0; i < n; i++) {
		fread(&x, sizeof(QuanLyHoSo), 1, f);
		p = GetNodeQLHSTS(x);
        ChenDauDSQLHoSo(Q, p);

	}
    cout << "\nSuccessfully Read File!";
	fclose(f);
}

// OPTION 14: Đọc DSQLKhoa từ File
void ReadFileFaculty(DoubleDanhSachQuanLyKhoa& DQ) {
	FILE* f;
	QuanLyKhoa x;
	int i, n;
	DoubleNodeQuanLyKhoa* p;

	f = fopen("FacultyList.dat", "rb");
	fread(&n, sizeof(int), 1, f);

	for (i = 0; i < n; i++) {
		fread(&x, sizeof(QuanLyKhoa), 1, f);
		p = GetDoubleNodeQLK(x);
        ChenDauDSQLKhoa(DQ, p);
	}
    cout << "\nSuccessfully Read File!";
	fclose(f);
}

// OPTION 15: Sort Profile By Ascending Name
void SortHoSoTheoTenASC(DanhSachQuanLyHoSo& Q) {
	QuanLyHoSo temp;
	NodeQuanLyHoSo* p, * q;
	for (p = Q.Head; p != NULL; p = p->next) {
		for (q = Q.Head; q != NULL; q = q->next) {
			if (strcmp(p->info.sinhVien.sTenSV, q->info.sinhVien.sTenSV) > 0) {
				SwapNode(p, q);
			}
		}
	}
	cout << "\nSorted Successfully ASC!";
}
// OPTION 16: Sort Profile By Descending Name
void SortHoSoTheoTenDESC(DanhSachQuanLyHoSo& Q) {
	QuanLyHoSo temp;
	NodeQuanLyHoSo* p, * q;
	for (p = Q.Head; p != NULL; p = p->next) {
		for (q = Q.Head; q != NULL; q = q->next) {
			if (strcmp(p->info.sinhVien.sTenSV, q->info.sinhVien.sTenSV) < 0) {
				SwapNode(p, q);
			}
		}
	}
	cout << "\nSorted Successfully DESC!";
}

// OPTION 17: Update Ten sinh vien theo ma SV trong HS
void SuaTenSVTheoMaSV(DanhSachQuanLyHoSo& Q) {
	string h;
	char newName[100];
	cin.ignore();
	cout << "\nNhap ma ho so can sua: "; cin >> h;

	NodeQuanLyHoSo* p;
	p = TimKiemHoSoTheoMaSV(Q, h);

	if (p == NULL)
		cout << "\nMã hồ sơ không hợp lệ!\n";
	else
		for (p = Q.Head; p != NULL; p = p->next) {
			if (p->info.sinhVien.sMaSV == h) {
				cin.ignore();
				cout << "Nhap moi cua sinh vien co ma - " << h << ": ";
				cin.getline(newName, 100);
				strcpy(p->info.sinhVien.sTenSV, newName);
				cout << "\nUpdated Succesfully";
			}
		}
}

void tongDiemAllSB (DanhSachQuanLyHoSo& Q) {
    NodeQuanLyHoSo* p;
    float tongSoDiem = 0.0f;

    for (p = Q.Head; p != NULL; p = p->next) {
		tongSoDiem += p->info.sinhVien.fTongDiem;
	}

    cout << "Tong so diem tat ca cac hssv la: " << tongSoDiem << endl;
}

void tongNganhAllKhoa (DoubleDanhSachQuanLyKhoa& DQ) {
    DoubleNodeQuanLyKhoa* p;
    int tongSoNganh = 0;

    for (p = DQ.Head; p != NULL; p = p->next) {
		tongSoNganh += p->info.khoa.iSoLuongNganh;
	}

    cout << "Tong so nganh cua tat cac cac khoa la: " << tongSoNganh << endl;
}

void inRaHSSVTongDiemLonHon28 (DanhSachQuanLyHoSo Q) {
    NodeQuanLyHoSo* p;
    for (p = Q.Head; p != NULL; p = p->next) {
        if (p->info.sinhVien.fTongDiem > 28) {
            HienSinhVien(p->info.sinhVien);
        }
    }
}

// Yeu cau 2:
void inSVCoSoNVTuyenThangBang1 (DanhSachQuanLyHoSo Q) {
    NodeQuanLyHoSo* p;
    for (p = Q.Head; p != NULL; p = p->next) {
        if (p->info.sinhVien.iSoNVTuyenThang == 1) {
            cout << p->info.sinhVien.sTenSV << endl;
        }
    }
}

// Yeu cau 3:
void SortSVTheoSoNVTuyenThangGiamDan (DanhSachQuanLyHoSo Q) {
    QuanLyHoSo temp;
	NodeQuanLyHoSo* p, * q;
	for (p = Q.Head; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (p->info.sinhVien.iSoNVTuyenThang < q->info.sinhVien.iSoNVTuyenThang) {
				SwapNode(p, q);
			}
		}
	}
	cout << "\n Sap xep thanh cong theo so nguyen vong tuyen thang giam dan!";
}
// =================================================================================== MENU SYSTEM

void MenuTitle()
{
	cout << "============= QUAN LY HO SO TUYEN SINH DAI HOC ===========\n";
	cout << "|| 1. Nhap danh sach quan ly ho so tuyen sinh           ||\n";
	cout << "|| 2. Nhap danh sach quan ly khoa                       ||\n";
	cout << "|| 3. Hien danh sach quan ly ho so tuyen sinh           ||\n";
	cout << "|| 4. Hien danh sach khoa quan ly                       ||\n";
	cout << "|| 5. Sap xep DS ho so theo tong diem giam dan (DESC)   ||\n";
	cout << "|| 6. Sap xep DS ho so theo tong diem tang dan (ASC)    ||\n";
	cout << "|| 7. Tim kiem ho so theo ma ho so                      ||\n";
	cout << "|| 8. Xoa ho so dau trong DS                            ||\n";
	cout << "|| 9. Tim ho so co tong diem Max                        ||\n";
	cout << "|| 10. Tim ho so co tong diem Min                       ||\n";
	cout << "|| 11. Luu DS ho so vao file                            ||\n";
	cout << "|| 12. Luu DS khoa quan ly vao file                     ||\n";
	cout << "|| 13. Doc DS ho so tu file                             ||\n";
	cout << "|| 14. Doc Ds khoa quan ly tu file                      ||\n";
	cout << "|| 15. Sap xep DS ho so theo ten SV ASC                 ||\n";
	cout << "|| 16. Sap xep DS ho so theo ten SV DESC                ||\n";
	cout << "|| 17. Sua Ten sinh vien theo ma SV trong DS Ho so      ||\n";
	cout << "|| 18. In ten SV co so nguyen vong tuyen thang bang 1   ||\n";
	cout << "|| 19. SX SV theo so nguyen vong tuyen thang giam dan   ||\n";
	cout << "|| 0. EXIT                                              ||\n";
	cout << "=========================================================\n";
}

int MenuChoice()
{
	int m = 0;
	cout << "\nNhap lua chon (int): ";
	cin >> m;
	if (m >= 0 || m < 0)
	{
		return m;
	}
	else
	{
		return MenuChoice();
	}
}

void MenuExecutor()
{
	int number = MenuChoice();
	switch (number) {
	case 1:
	{	NhapDanhSachQLHSTS(QLHSTS);
		break;
	}
	case 2:
	{	NhapDanhSachQLKhoa(QLK);
		break;
	}
	case 3:
	{	HienDSQLHoSo(QLHSTS);
		break;
	}
	case 4:
	{	HienDSQlKhoa(QLK);
		break;
	}
	case 5: {
		SortTongDiemDESC(QLHSTS);
		break;
	}
	case 6:
	{	SortTongDiemASC(QLHSTS);
		break;
	}
	case 7:
	{	TimKiemHoSoTheoMaStringH(QLHSTS);
		break;
	}
	case 8:
	{	RemoveHead(QLHSTS);
		break;
	}
	case 9:
	{	TimHoSoDiemMax(QLHSTS);
		break;
	}
	case 10:
	{	TimHoSoDiemMin(QLHSTS);
		break;
	}
	case 11:{
		SaveFile(QLHSTS);
		break;
	}
	case 12: {
		SaveFileFaculty(QLK);
		break;
	}
	case 13: {
		ReadFile(QLHSTS);
		break;
	}
	case 14: {
		ReadFileFaculty(QLK);
		break;
	}
	case 15: {
		SortHoSoTheoTenASC(QLHSTS);
		break;
	}
	case 16: {
		SortHoSoTheoTenDESC(QLHSTS);
		break;
	}
	case 17: {
		SuaTenSVTheoMaSV(QLHSTS);
		break;
	}
	case 18: {
	    cout << "==== DANH SACH SINH VIEN CO SO NV TUYEN THANG BANG 1" << endl;
        inSVCoSoNVTuyenThangBang1(QLHSTS);
        break;
	}
	case 19: {
        SortSVTheoSoNVTuyenThangGiamDan(QLHSTS);
        break;
	}
	/*case 18: {
		KiemTraSVTrungTuyen(QLHSTS, QLK);
		break;
	}
	case 19: {
        tongDiemAllSB(QLHSTS);
        break;
	}
	case 20: {
        tongNganhAllKhoa(QLK);
        break;
	}
	case 21: {
        inRaHSSVTongDiemLonHon28(QLHSTS);
        break;
	}*/
	case 0:{
		exit(0);
		break;
	}
	default: {
		cout << "\nLua chon that bai! Moi ban nhap lai...";
		break;
	}
	}
}

void MenuManagement() {
	while (true)
	{
		MenuTitle();
		MenuExecutor();
		cout << "\n\n";
		system("pause");
		system("cls");
	}
}
// =================================================================================== MAIN FUNCTION

int main() {
	KhoiTaoDSQuanLyHoSo(QLHSTS);
	MenuManagement();
	return 0;
}
