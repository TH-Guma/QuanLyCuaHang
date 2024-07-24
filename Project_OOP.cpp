#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class SanPham
{
private:
	int id_sp;
	string name_sp;
	int soluong;
	double gia;

public:
	static int rank_sp;

	void in_sp() {
		cout << "Nhap ID san pham: " << endl;
		cin >> id_sp;
		cin.ignore();
		cout << "Nhap ten san pham: " << endl;
		getline(cin, name_sp);
		cout << "Nhap so luong san pham: " << endl;
		cin >> soluong;
		cout << "Nhap gia san pham: " << endl;
		cin >> gia;
	}

	void out_sp() {
		cout << "\n" << id_sp << "\t" << name_sp << "\t\t" << soluong << "\t" << gia << "\n";
	}

	SanPham(int id_sp, string name_sp, int soluong, double gia)
	{
		this->id_sp = id_sp;
		this->name_sp = name_sp;
		this->soluong = soluong;
		this->gia = gia;
	}

	SanPham()
	{
		rank_sp++;
		this->id_sp = id_sp;
		this->name_sp = "Khong co";
		this->soluong = soluong;
		this->gia = gia;
	}

	int set_id_sp(int id_sp) {
		this->id_sp = id_sp;
	}

	string set_name_sp(string name_sp) {
		this->name_sp = name_sp;
	}

	int set_soluong(int soluong) {
		this->soluong = soluong;
		return soluong;
	}

	int get_id_sp() {
		return id_sp;
	}

	string get_name_sp() {
		return name_sp;
	}

	int get_soluong_sp() {
		return soluong;
	}

	int get_gia_sp() {
		return gia;
	}

	void get_sp() {
		get_id_sp();
		get_name_sp();
		get_soluong_sp();
		get_gia_sp();
	}
};

class KhachHang {
private:
	string name;
	int id_kh;
	long sdt;
public:
	static int rank_kh;
	void in_kh()
	{
		cout << "Nhap ID khach hang: ";
		cin >> id_kh;
		cin.ignore();
		cout << "Nhap ho ten khach: ";
		getline(cin, name);
		cout << "Nhap so dien thoai khach hang: ";
		cin >> sdt;
	}
	void out()
	{
		cout << "\n" << id_kh << "\t" << name << "\t" << sdt << "\n";
	}

	KhachHang(int id_kh, string name, long sdt)
	{
		this->id_kh = id_kh;
		this->name = name;
		this->sdt = sdt;
	}

	KhachHang()
	{
		rank_kh++;
		this->id_kh = id_kh;
		this->name = "Khong co";
		this->sdt = sdt;
	}

	string get_name_kh()
	{
		return name;
	}

	int get_id_kh()
	{
		return id_kh;
	}

	int get_sdt()
	{
		return sdt;
	}
};

class GioHang : public SanPham, KhachHang
{
public:
	vector <KhachHang> kh;
	vector <SanPham> sp;
	vector <int> soluong;

	void out_gh() {
		for (int i = 0; i < sp.size(); i++) {
			sp[i].out_sp();
		}
	}

	double total_gh() {
		double total = 0;
		for (int i = 0; i < sp.size(); i++) {
			total += sp[i].get_gia_sp() * sp[i].get_soluong_sp(); // Tính tổng giá của từng sản phẩm nhân với số lượng tương ứng
		}
		return total;
	}

	void add_sp(const SanPham SP, int n) {
		sp.push_back(SP);
		soluong.push_back(n);
	}
};

class CuaHang {
private:
	vector <GioHang> gh;
	vector <SanPham> sp;
	vector <KhachHang> kh;
public:
	void add_sp()
	{
		SanPham SP;
		SP.in_sp();
		sp.push_back(SP);
		cout << "Them san pham thanh cong!" << endl;
	}

	void remove_sp() {
		int x;
		cout << "Nhap ID san pham can xoa: ";
		cin >> x;
		int hold = 1;
		for (int i = 0; i < sp.size(); i++) {
			if (sp[i].get_id_sp() == x) {
				sp.erase(sp.begin() + i);
				SanPham::rank_sp--;
				cout << "\nDa xoa san pham\n";
				hold = 0;
			}
		}
		if (hold) {
			cout << "\nKhong co san pham trong danh sach\n";
		}
	}

	void sapxep_sp() {
		for (int i = 0; i < (sp.size() - 1); i++) {
			for (int j = i + 1; j < sp.size(); j++) {
				if (sp[i].get_id_sp() > sp[j].get_id_sp()) {
					swap(sp[i], sp[j]);
				}
			}
		}
		cout << "Qua trinh da hoan tat!" << endl;
	}

	void sapxep_kh() {
		for (int i = 0; i < (kh.size() - 1); i++) {
			for (int j = i + 1; j < kh.size(); j++) {
				if (kh[i].get_id_kh() > kh[j].get_id_kh()) {
					swap(kh[i], kh[j]);
				}
			}
		}cout << "Qua trinh da hoan tat!" << endl;
	}

	void add_kh()
	{
		KhachHang KH;
		KH.in_kh();
		kh.push_back(KH);
		cout << "Qua trinh da hoan tat!" << endl;
	}

	void remove_kh() {
		int x;
		cout << "Nhap ID khach hang can xoa: ";
		cin >> x;
		int hold = 1;
		for (int i = 0; i < kh.size(); i++) {
			if (kh[i].get_id_kh() == x) {
				kh.erase(kh.begin() + i);
				KhachHang::rank_kh--;
				cout << "\nDa xoa khach hang\n";
				hold = 0;
			}
		}
		if (hold) {
			cout << "\nKhong co khach hang can xoa trong danh sach\n";
		}
	}
	
	void add_gh() {
		int id, n;
		cout << "\nNhap ID san pham ma ban muon them vao gio hang: " << endl;
		cin >> id;
		cout << "\nNhap so luong san pham ma ban muon them vao gio hang: " << endl;
		cin >> n;
		SanPham* SP = nullptr;
		for (int i = 0; i < sp.size(); i++) {
			if (sp[i].get_id_sp() == id) {
				sp[i].get_soluong_sp();
				SP = &sp[i];
				break;
			}
		}

		if (SP != nullptr) {
			if (SP -> get_soluong_sp() >= n) {
				SanPham new_sp = *SP;
				new_sp.set_soluong(n);
				GioHang GH;
				GH.add_sp(new_sp, n); // Giả sử add_sp là phương thức để thêm sản phẩm vào giỏ hàng trong GioHang
				gh.push_back(GH);
				SP -> set_soluong(SP -> get_soluong_sp() - n);
				cout << "\nSan pham da duoc them vao gio hang.\n";
			}
			else {
				cout << "\nSo luong san pham khong du.\n";
			}
		}
		else {
			cout << "\nKhong tim thay san pham voi ID " << id << endl;
		}
	}

	void display_sp() {
		
		cout << "\n==============Danh sach san pham trong gio hang:================\n";
		cout << "\nID\tTenSP\t\tSoLuong\tGia\n";
		for (int i = 0; i < gh.size(); i++) {
			gh[i].out_gh(); // Hiển thị thông tin của sản phẩm trong giỏ hàng
		}
	}

	void remove_gh() {
		int id;
		cout << "\nNhap ID san pham ma ban muon bo khoi gio hang: " << endl;
		cin >> id;
		for (int i = 0; i < gh.size(); i++) {
			for (int j = 0; j < gh[i].sp.size(); j++) { // Duyệt qua các sản phẩm trong giỏ hàng
				if (gh[i].sp[j].get_id_sp() == id) { // Kiểm tra ID của sản phẩm
					gh[i].sp.erase(gh[i].sp.begin() + j); // Xóa sản phẩm khỏi giỏ hàng
					cout << "\nSan pham da duoc xoa khoi gio hang.\n";
					return;
				}
			}
		}
		cout << "\nKhong tim thay ID san pham : " << endl;
	}

	double total_gh() {
		double total = 0;
		for (int i = 0; i < gh.size(); i++) {
			for (int j = 0; j < gh[i].sp.size(); j++) { // Duyệt qua các sản phẩm trong giỏ hàng
				total += gh[i].sp[j].get_gia_sp() * gh[i].sp[j].get_soluong_sp();
				}
			}
		return total;
	}

	void DocFile_SP() {
		ifstream file;
		file.open("Ds_SanPham.csv");
		if (!file.is_open()) {
			cout << "KHONG DOC DUOC FILE!!";
			return;
		}
		while (file.peek() != EOF) {
			string id; string ten; string slg; string gia;
			int id_int, slg_int, gia_int;

			getline(file, id, ';');
			stringstream(id) >> id_int;

			getline(file, ten, ';');

			getline(file, slg, ';');
			stringstream(slg) >> slg_int;

			getline(file, gia);
			stringstream(gia) >> gia_int;

			SanPham sp_temp = SanPham(id_int, ten, slg_int, gia_int);
			sp.push_back(sp_temp);
		}
		cout << "Doc File Thanh Cong!!" << endl;
		file.close();
	}

	void DocFile_KH() {
		ifstream file;
		file.open("Ds_KhachHang.csv");
		if (!file.is_open()) {
			cout << "KHONG DOC DUOC FILE!!";
			return;
		}
		while(file.peek() != EOF){
			string id, ten, sdt;
			int int_id, int_sdt;

			getline(file, id, ';');
			stringstream(id) >> int_id;
			
			getline(file, ten, ';');

			getline(file, sdt);
			stringstream(sdt) >> int_sdt;

			KhachHang kh_temp = KhachHang(int_id, ten, int_sdt);
			kh.push_back(kh_temp);
		}		
		cout << "Doc File Thanh Cong!!" << endl;
		file.close();
	}

	void out_file_sp() {
		for (int i = 0; i < sp.size(); i++) {
			sp[i].out_sp();
		}
	}

	void out_file_kh() {
		for (int i = 0; i < kh.size(); i++) {
			kh[i].out();
		}
	}

	void MENU()
	{
		int choose;
		do
		{
			system("cls");
			cout << "========================CUA HANG======================" << endl;

			cout << "1. Danh sach san pham " << endl;

			cout << "2. Danh sach khach hang " << endl;

			cout << "3. Gio hang cua khach " << endl;

			cout << "4. Thoat chuong trinh" << endl;

			cout << "\nVui Long Nhap Lua Chon: " << endl;
			cin >> choose;

			switch (choose) {
			case 1:
				int choose_sp;
				do {
					cout << "\n=================QUAN LY SAN PHAM==================" << endl;

					cout << "1. Doc danh sach san pham" << endl;

					cout << "2. Hien thi san pham" << endl;

					cout << "3. Them san pham: " << endl;

					cout << "4. Sap xep san pham theo ID " << endl;

					cout << "5. Xoa san pham: " << endl;

					cout << "6. Thoat" << endl;

					cout << "\nVui Long Nhap Lua Chon: " << endl;
					cin >> choose_sp;

					switch (choose_sp) {
					case 1:
						DocFile_SP();
						break;
					case 2:
						cout << "\nID\tTenSanPham\tSoLuong\tGia" << endl;
						out_file_sp();
						break;
					case 3:
						add_sp();
						break;
					case 4:
						sapxep_sp();
						break;
					case 5:
						remove_sp();
						break;
					case 6:
						cout << "Cam on ban da su dung dich vu!\n";
						break;
					default:
						cout << "Lua chon khong hop le. Vui long nhap lai.\n";
					}
					system("pause");
				} while (choose_sp != 6);
				break;
			case 2:
				int choose_kh;
				do {
					cout << "\n=====================QUAN LY KHACH HANG=====================" << endl;

					cout << "1. Doc danh sach khach hang" << endl;

					cout << "2. Hien thi danh sach khach hang: " << endl;

					cout << "3. Them khach hang: " << endl;

					cout << "4. Sap xep khach hang theo ID" << endl;

					cout << "5. Xoa khach hang" << endl;

					cout << "6. Thoat" << endl;

					cout << "\nVui Long Nhap Lua Chon: " << endl;
					cin >> choose_kh;

					switch (choose_kh) {
					case 1:
						DocFile_KH();
						break;
					case 2:
						cout << "ID\tTenKhachHang\tSoDienThoai" << endl;
						out_file_kh();
						break;
					case 3:
						add_kh();
						break;
					case 4:
						sapxep_kh();
						break;
					case 5:
						remove_kh();
						break;
					case 6:
						cout << "Cam on ban da su dung dich vu!\n";
						break;
					default:
						cout << "Lua chon khong hop le. Vui long nhap lai.\n";
					}
					system("pause");
				} while (choose_kh != 6);
				break;

			case 3:
				int id;
				cout << "\n====================QUAN LY GIO HANG====================" << endl;
				cout << "Nhap ID khach hang:" << endl;
				cin >> id;
				cout << "KHACH HANG: " << kh[id - 1].get_name_kh() << endl;
				int choose_gh;
				do {
					cout << "1. Them vao gio hang " << endl;

					cout << "2. Xoa khoi gio hang " << endl;

					cout << "3. Xem gio hang " << endl;

					cout << "4. Thanh Toan " << endl;

					cout << "5. Thoat" << endl;

					cout << "Vui Long Nhap Lua Chon: " << endl;
					cin >> choose_gh;

					switch (choose_gh) {

					case 1:
						cout << "Danh sach san pham co trong cua hang" << endl;
						out_file_sp();
						add_gh();
						cout << "Danh sach san pham co trong cua hang" << endl;
						out_file_sp();
						break;
					case 2:
						remove_gh();
						break;
					case 3:
						display_sp();
						break;
					case 4:
						cout << "So tien phai thanh toan la: " << total_gh() << endl;
						break;
					case 5:
						cout << "Cam on ban da su dung dich vu!\n";
						break;
					default:
						cout << "Lua chon khong hop le. Vui long nhap lai.\n";
					}
					system("pause");
				} while (choose_gh != 5);
				break;

			case 4:
				cout << "Cam on da su dung dich vu!!!" << endl;
				return;
			default:
				cout << "Lua chon khong hop le. Vui long nhap lai.\n";
			}
		} while (true);
	}
};

int SanPham::rank_sp = 0;
int KhachHang::rank_kh = 0;

int main() {
	CuaHang ch;
	ch.MENU();
	return 0;
}