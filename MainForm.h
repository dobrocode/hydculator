#pragma once
#include "AboutForm.h"
#include "Math.h"
#include "Windows.h"
#include <string>
#include <vcclr.h>

namespace hydculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// площадь круга, по умлочанию диаметр в мм, площадь в см², разность величин отражается в k
	double SRound(double diameter, double k = 10) {
		return (diameter / 2 / k) * (diameter / 2 / k) * Math::PI;
	}

	// set ini value
	void SetIniValue(System::String^ name, System::String^ value) {
		pin_ptr<const wchar_t> wname = PtrToStringChars(name);
		pin_ptr<const wchar_t> wvalue = PtrToStringChars(value);
		WritePrivateProfileString(L"VALUES", wname, wvalue, L".\\hydculator.ini");
	}

	// get ini value
	System::String^ GetIniValue(System::String^ name) {
		pin_ptr<const wchar_t> wname = PtrToStringChars(name);
		WCHAR value[16];
		int a = GetPrivateProfileString(L"VALUES", wname, L"", value, 16, L".\\hydculator.ini");
		return gcnew String(value);
	}

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			// Number Format Info
			nfi = gcnew Globalization::NumberFormatInfo();
			nfi->NumberDecimalSeparator =".";
			nfi->NumberGroupSeparator ="";

			// возвращение значений
			for each (Control ^ tab in tabControl1->Controls)
			{
				for each (Control ^ c in tab->Controls)
				{
					if (c->GetType()->ToString() == L"System.Windows.Forms.TextBox") {
						c->Text = GetIniValue(c->Name);
					}
				}
			}

			// tabControl selected index
			String^ s = GetIniValue("TabIndex");
			double d;
			if (Double::TryParse(s, Globalization::NumberStyles::Float, nfi, d)) {
				int index = (int)d;
				if (index >= 0 && index < tabControl1->TabCount) {
					tabControl1->SelectedIndex = index;
				}
			}


			s = GetIniValue("COUNT_DECIMAL");
			if (Double::TryParse(s, Globalization::NumberStyles::Float, nfi, d)) {
				COUNT_DECIMAL = (int)d;
			}
			else {
				COUNT_DECIMAL = 3;
			}

			
		}

	public:

	private: Globalization::NumberFormatInfo^ nfi;

	// кол-во цифр после запятой
	private: int COUNT_DECIMAL;

	private: System::Windows::Forms::RichTextBox^ richTextBoxDT_info;

	private: System::Windows::Forms::GroupBox^ groupBoxDT_res;

	private: System::Windows::Forms::TextBox^ textBoxDT_resV;



	private: System::Windows::Forms::TextBox^ textBoxDT_resQ;
	private: System::Windows::Forms::Label^ labelDT_resV;


	private: System::Windows::Forms::Label^ labelDT_resQ;

	private: System::Windows::Forms::TextBox^ textBoxDT_resD;
	private: System::Windows::Forms::Label^ labelDT_resD;


	private: System::Windows::Forms::Button^ buttonDT_Enter;



	private: System::Windows::Forms::TextBox^ textBoxDT_Q;

	private: System::Windows::Forms::Label^ labelDT_Q;

	private: System::Windows::Forms::TextBox^ textBoxDT_V;
	private: System::Windows::Forms::Label^ labelDT_V;


	private: System::Windows::Forms::TextBox^ textBoxDT_D;
	private: System::Windows::Forms::Label^ labelDT_D;





	private: System::Windows::Forms::Label^ labelDT_Header;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::RichTextBox^ richTextBoxPG_info;
	private: System::Windows::Forms::GroupBox^ groupBoxPG_res;
	private: System::Windows::Forms::TextBox^ textBoxPG_SK;



	private: System::Windows::Forms::TextBox^ textBoxPG_SP;

	private: System::Windows::Forms::Label^ labelPG_SK;

	private: System::Windows::Forms::Label^ labelPG_SP;
	private: System::Windows::Forms::TextBox^ textBoxPG_SSh;


	private: System::Windows::Forms::Label^ labelPG_SSh;

	private: System::Windows::Forms::Button^ buttonPG_Enter;
	private: System::Windows::Forms::TextBox^ textBoxPG_LSh;


	private: System::Windows::Forms::Label^ labelPG_LSh;
	private: System::Windows::Forms::TextBox^ textBoxBG_DSh;


	private: System::Windows::Forms::Label^ labelPG_DSh;
	private: System::Windows::Forms::TextBox^ textBoxPG_DP;


	private: System::Windows::Forms::Label^ labelPG_DP;
	private: System::Windows::Forms::TextBox^ textBoxPG_n;


	private: System::Windows::Forms::Label^ labelPG_n;

	private: System::Windows::Forms::Label^ labelPG_Header;
	private: System::Windows::Forms::TextBox^ textBoxPG_V;


	private: System::Windows::Forms::Label^ labelPG_V;
	private: System::Windows::Forms::TextBox^ textBoxPG_P;


	private: System::Windows::Forms::Label^ labelPG_P;
	private: System::Windows::Forms::TextBox^ textBoxPG_VPP;


	private: System::Windows::Forms::Label^ labelPG_VPP;
	private: System::Windows::Forms::TextBox^ textBoxPG_SumFVt;



	private: System::Windows::Forms::Label^ labelPG_SumFVt;
	private: System::Windows::Forms::TextBox^ textBoxPG_SumFV;


	private: System::Windows::Forms::Label^ labelPG_SumFV;
	private: System::Windows::Forms::TextBox^ textBoxPG_NVC;


	private: System::Windows::Forms::Label^ labelPG_NVC;
	private: System::Windows::Forms::TextBox^ textBoxPG_DQPShP;


	private: System::Windows::Forms::Label^ labelPG_DQPShP;
	private: System::Windows::Forms::TextBox^ textBoxPG_FVtSh;


	private: System::Windows::Forms::Label^ labelPG_FVtSh;
	private: System::Windows::Forms::TextBox^ textBoxPG_FShC;


	private: System::Windows::Forms::Label^ labelPG_FShC;
	private: System::Windows::Forms::TextBox^ textBoxPG_NVtSh;


	private: System::Windows::Forms::Label^ labelPG_NVtSh;
	private: System::Windows::Forms::TextBox^ textBoxPG_QPP;



	private: System::Windows::Forms::Label^ labelPG_QPP;
	private: System::Windows::Forms::TextBox^ textBoxPG_QVSh;


	private: System::Windows::Forms::Label^ labelPG_QVSh;
	private: System::Windows::Forms::TextBox^ textBoxPG_CVShP;


	private: System::Windows::Forms::Label^ labelPG_CVShP;
	private: System::Windows::Forms::TextBox^ textBoxPG_VShP;


	private: System::Windows::Forms::Label^ labelPG_VShP;
	private: System::Windows::Forms::TextBox^ textBoxPG_CVPP;


	private: System::Windows::Forms::Label^ labelPG_CVPP;
	private: System::Windows::Forms::TabPage^ tabPageRG;
	private: System::Windows::Forms::TextBox^ textBoxRG_Sp;

	private: System::Windows::Forms::Label^ labelRG_Sp;
	private: System::Windows::Forms::TextBox^ textBoxRG_t;


	private: System::Windows::Forms::Label^ labelRG_t;
	private: System::Windows::Forms::TextBox^ textBoxRG_L;


	private: System::Windows::Forms::Label^ labelRG_L;
	private: System::Windows::Forms::RichTextBox^ richTextBoxRG_Info;
	private: System::Windows::Forms::GroupBox^ groupBoxRG_res;
	private: System::Windows::Forms::TextBox^ textBoxRG_resv;




	private: System::Windows::Forms::Label^ labelRG_resv;
	private: System::Windows::Forms::TextBox^ textBoxRG_resfi;


	private: System::Windows::Forms::TextBox^ textBoxRG_resSp;

	private: System::Windows::Forms::Label^ labelRG_resfi;

	private: System::Windows::Forms::Label^ labelRG_resSp;
	private: System::Windows::Forms::TextBox^ textBoxRG_resP;


	private: System::Windows::Forms::Label^ labelRG_resP;

	private: System::Windows::Forms::Button^ buttonRG_Enter;
	private: System::Windows::Forms::TextBox^ textBoxRG_fi;


	private: System::Windows::Forms::Label^ labelRG_fi;
	private: System::Windows::Forms::TextBox^ textBoxRG_P;


	private: System::Windows::Forms::Label^ labelRG_P;
	private: System::Windows::Forms::TextBox^ textBoxRG_n;


	private: System::Windows::Forms::Label^ labelRG_n;
	private: System::Windows::Forms::TextBox^ textBoxRG_Fst;


	private: System::Windows::Forms::Label^ labelRG_Fst;

	private: System::Windows::Forms::Label^ labelRG;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::RichTextBox^ richTextBoxPN_Info;
	private: System::Windows::Forms::GroupBox^ groupBoxPN_res;
	private: System::Windows::Forms::TextBox^ textBoxPN_resVg;
	private: System::Windows::Forms::Label^ labelPN_resVg;
	private: System::Windows::Forms::TextBox^ textBoxPN_resQ;
	private: System::Windows::Forms::Label^ labelPN_resQ;
	private: System::Windows::Forms::Button^ buttonPN_Enter;
	private: System::Windows::Forms::TextBox^ textBoxPN_Vg;
	private: System::Windows::Forms::Label^ labelPN_Vg;
	private: System::Windows::Forms::TextBox^ textBoxPN_eta;
	private: System::Windows::Forms::Label^ labelPN_eta;
	private: System::Windows::Forms::TextBox^ textBoxPN_n;
	private: System::Windows::Forms::Label^ labelPN_n;
	private: System::Windows::Forms::TextBox^ textBoxPN_Q;
	private: System::Windows::Forms::Label^ labelPN_Q;
	private: System::Windows::Forms::Label^ labelPN_Header;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::RichTextBox^ richTextBoxOG_Info;
	private: System::Windows::Forms::GroupBox^ groupBoxOG_res;
	private: System::Windows::Forms::TextBox^ textBoxOG_resn;
	private: System::Windows::Forms::Label^ labelOG_resn;
	private: System::Windows::Forms::Button^ buttonOG_Enter;
	private: System::Windows::Forms::Label^ labelOG_Vg;
	private: System::Windows::Forms::TextBox^ textBoxOG_eta;
	private: System::Windows::Forms::Label^ labelOG_eta;
	private: System::Windows::Forms::TextBox^ textBoxOG_Vg;
	private: System::Windows::Forms::TextBox^ textBoxOG_Q;
	private: System::Windows::Forms::Label^ labelOG_Q;
	private: System::Windows::Forms::Label^ labelOG_Header;
	private: System::Windows::Forms::TabPage^ tabPage6;
private: System::Windows::Forms::Label^ labelKMG_P;
private: System::Windows::Forms::RichTextBox^ richTextBoxKMG_Info;


private: System::Windows::Forms::GroupBox^ groupBoxKMG_res;
private: System::Windows::Forms::TextBox^ textBoxKMG_resVg;


private: System::Windows::Forms::TextBox^ textBoxKMG_resM;

private: System::Windows::Forms::Label^ labelKMG_resVg;

private: System::Windows::Forms::Label^ labelKMG_resM;
private: System::Windows::Forms::TextBox^ textBoxKMG_resP;


private: System::Windows::Forms::Label^ labelKMG_resP;

private: System::Windows::Forms::Button^ buttonKMG_Enter;
private: System::Windows::Forms::TextBox^ textBoxKMG_eta;


private: System::Windows::Forms::Label^ labelKMG_eta;
private: System::Windows::Forms::TextBox^ textBoxKMG_P;


private: System::Windows::Forms::TextBox^ textBoxKMG_Vg;

private: System::Windows::Forms::Label^ labelKMG_Vg;

private: System::Windows::Forms::TextBox^ textBoxKMG_M;

private: System::Windows::Forms::Label^ labelKMG_M;

private: System::Windows::Forms::Label^ labelKMG_Header;
private: System::Windows::Forms::RadioButton^ radioButtonKMG_resnm;



private: System::Windows::Forms::RadioButton^ radioButtonKMG_reskgm;







	//private: const double kWt2HF = 1.36;
	private: const double HF2kWt = 0.73549875;
private: System::Windows::Forms::TabPage^ tabPage7;
private: System::Windows::Forms::RichTextBox^ richTextBoxKMV_Info;
private: System::Windows::Forms::GroupBox^ groupBoxKMV_res;
private: System::Windows::Forms::RadioButton^ radioButtonKMV_resMhm;
private: System::Windows::Forms::RadioButton^ radioButtonKMV_resMkgm;
private: System::Windows::Forms::TextBox^ textBoxKMV_resM;
private: System::Windows::Forms::Label^ label6KMV_resM;
private: System::Windows::Forms::Button^ buttonKMV_Enter;
private: System::Windows::Forms::TextBox^ textBoxKMV_nn;
private: System::Windows::Forms::Label^ labelKMV_nn;
private: System::Windows::Forms::TextBox^ textBoxKMV_N;
private: System::Windows::Forms::Label^ labelKMV_N;
private: System::Windows::Forms::Label^ labelKMV_Header;
private: System::Windows::Forms::TabPage^ tabPage8;
private: System::Windows::Forms::PictureBox^ pictureBoxOPN_Img;

private: System::Windows::Forms::Label^ labelOPN_L;
private: System::Windows::Forms::RichTextBox^ richTextBoxOPN_Info;
private: System::Windows::Forms::GroupBox^ groupBoxOPN_res;
private: System::Windows::Forms::TextBox^ textBoxOPN_resV;







private: System::Windows::Forms::Label^ labelOPN_resV;



private: System::Windows::Forms::Button^ buttonOPN_Enter;



private: System::Windows::Forms::TextBox^ textBoxOPN_L;



private: System::Windows::Forms::TextBox^ textBoxOPN_D;

private: System::Windows::Forms::Label^ labelOPN_D;
private: System::Windows::Forms::TextBox^ textBoxOPN_W;


private: System::Windows::Forms::Label^ labelOPN_W;

private: System::Windows::Forms::Label^ labelOPN_Header;
private: System::Windows::Forms::TabPage^ tabPage9;
private: System::Windows::Forms::PictureBox^ pictureBoxOShN_Img;
private: System::Windows::Forms::Label^ labelOShN_L;
private: System::Windows::Forms::RichTextBox^ richTextBoxOShN_Info;
private: System::Windows::Forms::GroupBox^ groupBoxOShN_res;
private: System::Windows::Forms::TextBox^ textBoxOShN_resV;

private: System::Windows::Forms::Label^ labelOShN_resV;

private: System::Windows::Forms::Button^ buttonOShN_Enter;
private: System::Windows::Forms::TextBox^ textBoxOShN_L;
private: System::Windows::Forms::TextBox^ textBoxOShN_D;
private: System::Windows::Forms::Label^ labelOShN_D;
private: System::Windows::Forms::TextBox^ textBoxOShN_W;
private: System::Windows::Forms::Label^ labelOShN_W;
private: System::Windows::Forms::Label^ labelOShN_Header;
private: System::Windows::Forms::ToolStripMenuItem^ расчетToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ расчётМощностиРасходаИДавленияГидроприводаToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ расчётДиаметраТрубопроводаСкоростиПотокаToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ расчётПараметровГидроцилиндраПоЕгоРазмерамToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ расчётРазмеровГидроцилиндраПоТехническимПараметрамToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ расчётПодачиНасосаToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ расчётОборотовГидромотораToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ расчётКрутящегоМоментаГидромотораобъемИДавлениеToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ расчётКрутящегоМоментаНаВалумощностьИОборотыToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ расчётОбъёмаПластинчатогоНасосаПоГеометрическимРазмерамToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ расчётОбъёмаШестеренногоНасосаПоГеометрическимРазмерамToolStripMenuItem;


	private: const double G = 9.80665;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ textBoxGP_eta;
	private: System::Windows::Forms::Label^ labelGP_eta;
	private: System::Windows::Forms::TextBox^ textBoxGP_P;
	private: System::Windows::Forms::Label^ labelGP_P;
	private: System::Windows::Forms::TextBox^ textBoxGP_Q;
	private: System::Windows::Forms::Label^ labelGP_Q;
	private: System::Windows::Forms::TextBox^ textBoxGP_N;
	private: System::Windows::Forms::Label^ labelGP_N;
	private: System::Windows::Forms::Label^ labelGP_Header;
	private: System::Windows::Forms::Button^ buttonGP_Enter;
	private: System::Windows::Forms::GroupBox^ groupBoxGP_Results;
	private: System::Windows::Forms::RadioButton^ radioButtonGP_N2;
	private: System::Windows::Forms::RadioButton^ radioButtonGP_N1;
	private: System::Windows::Forms::TextBox^ textBoxGP_resP;

	private: System::Windows::Forms::TextBox^ textBoxGP_resN;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxGP_resQ;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ richTextBoxGP_info;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->расчетToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расчётМощностиРасходаИДавленияГидроприводаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расчётДиаметраТрубопроводаСкоростиПотокаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расчётПараметровГидроцилиндраПоЕгоРазмерамToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расчётРазмеровГидроцилиндраПоТехническимПараметрамToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расчётПодачиНасосаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расчётОборотовГидромотораToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расчётКрутящегоМоментаГидромотораобъемИДавлениеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расчётКрутящегоМоментаНаВалумощностьИОборотыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расчётОбъёмаПластинчатогоНасосаПоГеометрическимРазмерамToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расчётОбъёмаШестеренногоНасосаПоГеометрическимРазмерамToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBoxGP_info = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxGP_Results = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonGP_N2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonGP_N1 = (gcnew System::Windows::Forms::RadioButton());
			this->textBoxGP_resP = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGP_resN = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxGP_resQ = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonGP_Enter = (gcnew System::Windows::Forms::Button());
			this->textBoxGP_eta = (gcnew System::Windows::Forms::TextBox());
			this->labelGP_eta = (gcnew System::Windows::Forms::Label());
			this->textBoxGP_P = (gcnew System::Windows::Forms::TextBox());
			this->labelGP_P = (gcnew System::Windows::Forms::Label());
			this->textBoxGP_Q = (gcnew System::Windows::Forms::TextBox());
			this->labelGP_Q = (gcnew System::Windows::Forms::Label());
			this->textBoxGP_N = (gcnew System::Windows::Forms::TextBox());
			this->labelGP_N = (gcnew System::Windows::Forms::Label());
			this->labelGP_Header = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBoxDT_info = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxDT_res = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxDT_resV = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDT_resQ = (gcnew System::Windows::Forms::TextBox());
			this->labelDT_resV = (gcnew System::Windows::Forms::Label());
			this->labelDT_resQ = (gcnew System::Windows::Forms::Label());
			this->textBoxDT_resD = (gcnew System::Windows::Forms::TextBox());
			this->labelDT_resD = (gcnew System::Windows::Forms::Label());
			this->buttonDT_Enter = (gcnew System::Windows::Forms::Button());
			this->textBoxDT_Q = (gcnew System::Windows::Forms::TextBox());
			this->labelDT_Q = (gcnew System::Windows::Forms::Label());
			this->textBoxDT_V = (gcnew System::Windows::Forms::TextBox());
			this->labelDT_V = (gcnew System::Windows::Forms::Label());
			this->textBoxDT_D = (gcnew System::Windows::Forms::TextBox());
			this->labelDT_D = (gcnew System::Windows::Forms::Label());
			this->labelDT_Header = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->textBoxPG_V = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_V = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_P = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_P = (gcnew System::Windows::Forms::Label());
			this->richTextBoxPG_info = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxPG_res = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxPG_SumFVt = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_SumFVt = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_SumFV = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_SumFV = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_NVC = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_NVC = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_DQPShP = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_DQPShP = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_FVtSh = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_FVtSh = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_FShC = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_FShC = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_NVtSh = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_NVtSh = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_QPP = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_QPP = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_QVSh = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_QVSh = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_CVShP = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_CVShP = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_VShP = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_VShP = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_CVPP = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_CVPP = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_VPP = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_VPP = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_SK = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPG_SP = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_SK = (gcnew System::Windows::Forms::Label());
			this->labelPG_SP = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_SSh = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_SSh = (gcnew System::Windows::Forms::Label());
			this->buttonPG_Enter = (gcnew System::Windows::Forms::Button());
			this->textBoxPG_LSh = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_LSh = (gcnew System::Windows::Forms::Label());
			this->textBoxBG_DSh = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_DSh = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_DP = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_DP = (gcnew System::Windows::Forms::Label());
			this->textBoxPG_n = (gcnew System::Windows::Forms::TextBox());
			this->labelPG_n = (gcnew System::Windows::Forms::Label());
			this->labelPG_Header = (gcnew System::Windows::Forms::Label());
			this->tabPageRG = (gcnew System::Windows::Forms::TabPage());
			this->textBoxRG_Sp = (gcnew System::Windows::Forms::TextBox());
			this->labelRG_Sp = (gcnew System::Windows::Forms::Label());
			this->textBoxRG_t = (gcnew System::Windows::Forms::TextBox());
			this->labelRG_t = (gcnew System::Windows::Forms::Label());
			this->textBoxRG_L = (gcnew System::Windows::Forms::TextBox());
			this->labelRG_L = (gcnew System::Windows::Forms::Label());
			this->richTextBoxRG_Info = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxRG_res = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxRG_resv = (gcnew System::Windows::Forms::TextBox());
			this->labelRG_resv = (gcnew System::Windows::Forms::Label());
			this->textBoxRG_resfi = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRG_resSp = (gcnew System::Windows::Forms::TextBox());
			this->labelRG_resfi = (gcnew System::Windows::Forms::Label());
			this->labelRG_resSp = (gcnew System::Windows::Forms::Label());
			this->textBoxRG_resP = (gcnew System::Windows::Forms::TextBox());
			this->labelRG_resP = (gcnew System::Windows::Forms::Label());
			this->buttonRG_Enter = (gcnew System::Windows::Forms::Button());
			this->textBoxRG_fi = (gcnew System::Windows::Forms::TextBox());
			this->labelRG_fi = (gcnew System::Windows::Forms::Label());
			this->textBoxRG_P = (gcnew System::Windows::Forms::TextBox());
			this->labelRG_P = (gcnew System::Windows::Forms::Label());
			this->textBoxRG_n = (gcnew System::Windows::Forms::TextBox());
			this->labelRG_n = (gcnew System::Windows::Forms::Label());
			this->textBoxRG_Fst = (gcnew System::Windows::Forms::TextBox());
			this->labelRG_Fst = (gcnew System::Windows::Forms::Label());
			this->labelRG = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBoxPN_Info = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxPN_res = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxPN_resVg = (gcnew System::Windows::Forms::TextBox());
			this->labelPN_resVg = (gcnew System::Windows::Forms::Label());
			this->textBoxPN_resQ = (gcnew System::Windows::Forms::TextBox());
			this->labelPN_resQ = (gcnew System::Windows::Forms::Label());
			this->buttonPN_Enter = (gcnew System::Windows::Forms::Button());
			this->textBoxPN_Vg = (gcnew System::Windows::Forms::TextBox());
			this->labelPN_Vg = (gcnew System::Windows::Forms::Label());
			this->textBoxPN_eta = (gcnew System::Windows::Forms::TextBox());
			this->labelPN_eta = (gcnew System::Windows::Forms::Label());
			this->textBoxPN_n = (gcnew System::Windows::Forms::TextBox());
			this->labelPN_n = (gcnew System::Windows::Forms::Label());
			this->textBoxPN_Q = (gcnew System::Windows::Forms::TextBox());
			this->labelPN_Q = (gcnew System::Windows::Forms::Label());
			this->labelPN_Header = (gcnew System::Windows::Forms::Label());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBoxOG_Info = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxOG_res = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxOG_resn = (gcnew System::Windows::Forms::TextBox());
			this->labelOG_resn = (gcnew System::Windows::Forms::Label());
			this->buttonOG_Enter = (gcnew System::Windows::Forms::Button());
			this->labelOG_Vg = (gcnew System::Windows::Forms::Label());
			this->textBoxOG_eta = (gcnew System::Windows::Forms::TextBox());
			this->labelOG_eta = (gcnew System::Windows::Forms::Label());
			this->textBoxOG_Vg = (gcnew System::Windows::Forms::TextBox());
			this->textBoxOG_Q = (gcnew System::Windows::Forms::TextBox());
			this->labelOG_Q = (gcnew System::Windows::Forms::Label());
			this->labelOG_Header = (gcnew System::Windows::Forms::Label());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->labelKMG_P = (gcnew System::Windows::Forms::Label());
			this->richTextBoxKMG_Info = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxKMG_res = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonKMG_resnm = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonKMG_reskgm = (gcnew System::Windows::Forms::RadioButton());
			this->textBoxKMG_resVg = (gcnew System::Windows::Forms::TextBox());
			this->textBoxKMG_resM = (gcnew System::Windows::Forms::TextBox());
			this->labelKMG_resVg = (gcnew System::Windows::Forms::Label());
			this->labelKMG_resM = (gcnew System::Windows::Forms::Label());
			this->textBoxKMG_resP = (gcnew System::Windows::Forms::TextBox());
			this->labelKMG_resP = (gcnew System::Windows::Forms::Label());
			this->buttonKMG_Enter = (gcnew System::Windows::Forms::Button());
			this->textBoxKMG_eta = (gcnew System::Windows::Forms::TextBox());
			this->labelKMG_eta = (gcnew System::Windows::Forms::Label());
			this->textBoxKMG_P = (gcnew System::Windows::Forms::TextBox());
			this->textBoxKMG_Vg = (gcnew System::Windows::Forms::TextBox());
			this->labelKMG_Vg = (gcnew System::Windows::Forms::Label());
			this->textBoxKMG_M = (gcnew System::Windows::Forms::TextBox());
			this->labelKMG_M = (gcnew System::Windows::Forms::Label());
			this->labelKMG_Header = (gcnew System::Windows::Forms::Label());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBoxKMV_Info = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxKMV_res = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonKMV_resMhm = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonKMV_resMkgm = (gcnew System::Windows::Forms::RadioButton());
			this->textBoxKMV_resM = (gcnew System::Windows::Forms::TextBox());
			this->label6KMV_resM = (gcnew System::Windows::Forms::Label());
			this->buttonKMV_Enter = (gcnew System::Windows::Forms::Button());
			this->textBoxKMV_nn = (gcnew System::Windows::Forms::TextBox());
			this->labelKMV_nn = (gcnew System::Windows::Forms::Label());
			this->textBoxKMV_N = (gcnew System::Windows::Forms::TextBox());
			this->labelKMV_N = (gcnew System::Windows::Forms::Label());
			this->labelKMV_Header = (gcnew System::Windows::Forms::Label());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBoxOPN_Img = (gcnew System::Windows::Forms::PictureBox());
			this->labelOPN_L = (gcnew System::Windows::Forms::Label());
			this->richTextBoxOPN_Info = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxOPN_res = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxOPN_resV = (gcnew System::Windows::Forms::TextBox());
			this->labelOPN_resV = (gcnew System::Windows::Forms::Label());
			this->buttonOPN_Enter = (gcnew System::Windows::Forms::Button());
			this->textBoxOPN_L = (gcnew System::Windows::Forms::TextBox());
			this->textBoxOPN_D = (gcnew System::Windows::Forms::TextBox());
			this->labelOPN_D = (gcnew System::Windows::Forms::Label());
			this->textBoxOPN_W = (gcnew System::Windows::Forms::TextBox());
			this->labelOPN_W = (gcnew System::Windows::Forms::Label());
			this->labelOPN_Header = (gcnew System::Windows::Forms::Label());
			this->tabPage9 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBoxOShN_Img = (gcnew System::Windows::Forms::PictureBox());
			this->labelOShN_L = (gcnew System::Windows::Forms::Label());
			this->richTextBoxOShN_Info = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBoxOShN_res = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxOShN_resV = (gcnew System::Windows::Forms::TextBox());
			this->labelOShN_resV = (gcnew System::Windows::Forms::Label());
			this->buttonOShN_Enter = (gcnew System::Windows::Forms::Button());
			this->textBoxOShN_L = (gcnew System::Windows::Forms::TextBox());
			this->textBoxOShN_D = (gcnew System::Windows::Forms::TextBox());
			this->labelOShN_D = (gcnew System::Windows::Forms::Label());
			this->textBoxOShN_W = (gcnew System::Windows::Forms::TextBox());
			this->labelOShN_W = (gcnew System::Windows::Forms::Label());
			this->labelOShN_Header = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBoxGP_Results->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBoxDT_res->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBoxPG_res->SuspendLayout();
			this->tabPageRG->SuspendLayout();
			this->groupBoxRG_res->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->groupBoxPN_res->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->groupBoxOG_res->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->groupBoxKMG_res->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->groupBoxKMV_res->SuspendLayout();
			this->tabPage8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOPN_Img))->BeginInit();
			this->groupBoxOPN_res->SuspendLayout();
			this->tabPage9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOShN_Img))->BeginInit();
			this->groupBoxOShN_res->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->расчетToolStripMenuItem,
					this->оПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(792, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// расчетToolStripMenuItem
			// 
			this->расчетToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->расчётМощностиРасходаИДавленияГидроприводаToolStripMenuItem,
					this->расчётДиаметраТрубопроводаСкоростиПотокаToolStripMenuItem, this->расчётПараметровГидроцилиндраПоЕгоРазмерамToolStripMenuItem,
					this->расчётРазмеровГидроцилиндраПоТехническимПараметрамToolStripMenuItem, this->расчётПодачиНасосаToolStripMenuItem, this->расчётОборотовГидромотораToolStripMenuItem,
					this->расчётКрутящегоМоментаГидромотораобъемИДавлениеToolStripMenuItem, this->расчётКрутящегоМоментаНаВалумощностьИОборотыToolStripMenuItem,
					this->расчётОбъёмаПластинчатогоНасосаПоГеометрическимРазмерамToolStripMenuItem, this->расчётОбъёмаШестеренногоНасосаПоГеометрическимРазмерамToolStripMenuItem
			});
			this->расчетToolStripMenuItem->Name = L"расчетToolStripMenuItem";
			this->расчетToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->расчетToolStripMenuItem->Text = L"Расчеты";
			// 
			// расчётМощностиРасходаИДавленияГидроприводаToolStripMenuItem
			// 
			this->расчётМощностиРасходаИДавленияГидроприводаToolStripMenuItem->Name = L"расчётМощностиРасходаИДавленияГидроприводаToolStripMenuItem";
			this->расчётМощностиРасходаИДавленияГидроприводаToolStripMenuItem->Size = System::Drawing::Size(415, 22);
			this->расчётМощностиРасходаИДавленияГидроприводаToolStripMenuItem->Tag = L"0";
			this->расчётМощностиРасходаИДавленияГидроприводаToolStripMenuItem->Text = L"Расчёт мощности, расхода и давления гидропривода";
			this->расчётМощностиРасходаИДавленияГидроприводаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TabMenuItem_Click);
			// 
			// расчётДиаметраТрубопроводаСкоростиПотокаToolStripMenuItem
			// 
			this->расчётДиаметраТрубопроводаСкоростиПотокаToolStripMenuItem->Name = L"расчётДиаметраТрубопроводаСкоростиПотокаToolStripMenuItem";
			this->расчётДиаметраТрубопроводаСкоростиПотокаToolStripMenuItem->Size = System::Drawing::Size(415, 22);
			this->расчётДиаметраТрубопроводаСкоростиПотокаToolStripMenuItem->Tag = L"1";
			this->расчётДиаметраТрубопроводаСкоростиПотокаToolStripMenuItem->Text = L"Расчёт диаметра трубопровода, скорости потока";
			this->расчётДиаметраТрубопроводаСкоростиПотокаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TabMenuItem_Click);
			// 
			// расчётПараметровГидроцилиндраПоЕгоРазмерамToolStripMenuItem
			// 
			this->расчётПараметровГидроцилиндраПоЕгоРазмерамToolStripMenuItem->Name = L"расчётПараметровГидроцилиндраПоЕгоРазмерамToolStripMenuItem";
			this->расчётПараметровГидроцилиндраПоЕгоРазмерамToolStripMenuItem->Size = System::Drawing::Size(415, 22);
			this->расчётПараметровГидроцилиндраПоЕгоРазмерамToolStripMenuItem->Tag = L"2";
			this->расчётПараметровГидроцилиндраПоЕгоРазмерамToolStripMenuItem->Text = L"Расчёт параметров гидроцилиндра по его размерам";
			this->расчётПараметровГидроцилиндраПоЕгоРазмерамToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TabMenuItem_Click);
			// 
			// расчётРазмеровГидроцилиндраПоТехническимПараметрамToolStripMenuItem
			// 
			this->расчётРазмеровГидроцилиндраПоТехническимПараметрамToolStripMenuItem->Name = L"расчётРазмеровГидроцилиндраПоТехническимПараметрамToolStripMenuItem";
			this->расчётРазмеровГидроцилиндраПоТехническимПараметрамToolStripMenuItem->Size = System::Drawing::Size(415, 22);
			this->расчётРазмеровГидроцилиндраПоТехническимПараметрамToolStripMenuItem->Tag = L"3";
			this->расчётРазмеровГидроцилиндраПоТехническимПараметрамToolStripMenuItem->Text = L"Расчёт размеров гидроцилиндра по техническим параметрам";
			this->расчётРазмеровГидроцилиндраПоТехническимПараметрамToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TabMenuItem_Click);
			// 
			// расчётПодачиНасосаToolStripMenuItem
			// 
			this->расчётПодачиНасосаToolStripMenuItem->Name = L"расчётПодачиНасосаToolStripMenuItem";
			this->расчётПодачиНасосаToolStripMenuItem->Size = System::Drawing::Size(415, 22);
			this->расчётПодачиНасосаToolStripMenuItem->Tag = L"4";
			this->расчётПодачиНасосаToolStripMenuItem->Text = L"Расчёт подачи насоса";
			this->расчётПодачиНасосаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TabMenuItem_Click);
			// 
			// расчётОборотовГидромотораToolStripMenuItem
			// 
			this->расчётОборотовГидромотораToolStripMenuItem->Name = L"расчётОборотовГидромотораToolStripMenuItem";
			this->расчётОборотовГидромотораToolStripMenuItem->Size = System::Drawing::Size(415, 22);
			this->расчётОборотовГидромотораToolStripMenuItem->Tag = L"5";
			this->расчётОборотовГидромотораToolStripMenuItem->Text = L"Расчёт оборотов гидромотора";
			this->расчётОборотовГидромотораToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TabMenuItem_Click);
			// 
			// расчётКрутящегоМоментаГидромотораобъемИДавлениеToolStripMenuItem
			// 
			this->расчётКрутящегоМоментаГидромотораобъемИДавлениеToolStripMenuItem->Name = L"расчётКрутящегоМоментаГидромотораобъемИДавлениеToolStripMenuItem";
			this->расчётКрутящегоМоментаГидромотораобъемИДавлениеToolStripMenuItem->Size = System::Drawing::Size(415, 22);
			this->расчётКрутящегоМоментаГидромотораобъемИДавлениеToolStripMenuItem->Tag = L"6";
			this->расчётКрутящегоМоментаГидромотораобъемИДавлениеToolStripMenuItem->Text = L"Расчёт крутящего момента гидромотора (объем и давление)";
			this->расчётКрутящегоМоментаГидромотораобъемИДавлениеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TabMenuItem_Click);
			// 
			// расчётКрутящегоМоментаНаВалумощностьИОборотыToolStripMenuItem
			// 
			this->расчётКрутящегоМоментаНаВалумощностьИОборотыToolStripMenuItem->Name = L"расчётКрутящегоМоментаНаВалумощностьИОборотыToolStripMenuItem";
			this->расчётКрутящегоМоментаНаВалумощностьИОборотыToolStripMenuItem->Size = System::Drawing::Size(415, 22);
			this->расчётКрутящегоМоментаНаВалумощностьИОборотыToolStripMenuItem->Tag = L"7";
			this->расчётКрутящегоМоментаНаВалумощностьИОборотыToolStripMenuItem->Text = L"Расчёт крутящего момента на валу (мощность и обороты)";
			this->расчётКрутящегоМоментаНаВалумощностьИОборотыToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TabMenuItem_Click);
			// 
			// расчётОбъёмаПластинчатогоНасосаПоГеометрическимРазмерамToolStripMenuItem
			// 
			this->расчётОбъёмаПластинчатогоНасосаПоГеометрическимРазмерамToolStripMenuItem->Name = L"расчётОбъёмаПластинчатогоНасосаПоГеометрическимРазмерамToolStripMenuItem";
			this->расчётОбъёмаПластинчатогоНасосаПоГеометрическимРазмерамToolStripMenuItem->Size = System::Drawing::Size(415, 22);
			this->расчётОбъёмаПластинчатогоНасосаПоГеометрическимРазмерамToolStripMenuItem->Tag = L"8";
			this->расчётОбъёмаПластинчатогоНасосаПоГеометрическимРазмерамToolStripMenuItem->Text = L"Расчёт объёма пластинчатого насоса по геометрическим размерам";
			this->расчётОбъёмаПластинчатогоНасосаПоГеометрическимРазмерамToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TabMenuItem_Click);
			// 
			// расчётОбъёмаШестеренногоНасосаПоГеометрическимРазмерамToolStripMenuItem
			// 
			this->расчётОбъёмаШестеренногоНасосаПоГеометрическимРазмерамToolStripMenuItem->Name = L"расчётОбъёмаШестеренногоНасосаПоГеометрическимРазмерамToolStripMenuItem";
			this->расчётОбъёмаШестеренногоНасосаПоГеометрическимРазмерамToolStripMenuItem->Size = System::Drawing::Size(415, 22);
			this->расчётОбъёмаШестеренногоНасосаПоГеометрическимРазмерамToolStripMenuItem->Tag = L"9";
			this->расчётОбъёмаШестеренногоНасосаПоГеометрическимРазмерамToolStripMenuItem->Text = L"Расчёт объёма шестеренного насоса по геометрическим размерам";
			this->расчётОбъёмаШестеренногоНасосаПоГеометрическимРазмерамToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TabMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::оПрограммеToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPageRG);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Controls->Add(this->tabPage8);
			this->tabControl1->Controls->Add(this->tabPage9);
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(792, 585);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->richTextBoxGP_info);
			this->tabPage1->Controls->Add(this->groupBoxGP_Results);
			this->tabPage1->Controls->Add(this->buttonGP_Enter);
			this->tabPage1->Controls->Add(this->textBoxGP_eta);
			this->tabPage1->Controls->Add(this->labelGP_eta);
			this->tabPage1->Controls->Add(this->textBoxGP_P);
			this->tabPage1->Controls->Add(this->labelGP_P);
			this->tabPage1->Controls->Add(this->textBoxGP_Q);
			this->tabPage1->Controls->Add(this->labelGP_Q);
			this->tabPage1->Controls->Add(this->textBoxGP_N);
			this->tabPage1->Controls->Add(this->labelGP_N);
			this->tabPage1->Controls->Add(this->labelGP_Header);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(784, 559);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Расчет мощности, расхода и давления гидропривода";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// richTextBoxGP_info
			// 
			this->richTextBoxGP_info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxGP_info->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxGP_info->Location = System::Drawing::Point(15, 210);
			this->richTextBoxGP_info->Name = L"richTextBoxGP_info";
			this->richTextBoxGP_info->ReadOnly = true;
			this->richTextBoxGP_info->Size = System::Drawing::Size(760, 342);
			this->richTextBoxGP_info->TabIndex = 12;
			this->richTextBoxGP_info->Text = resources->GetString(L"richTextBoxGP_info.Text");
			// 
			// groupBoxGP_Results
			// 
			this->groupBoxGP_Results->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxGP_Results->Controls->Add(this->radioButtonGP_N2);
			this->groupBoxGP_Results->Controls->Add(this->radioButtonGP_N1);
			this->groupBoxGP_Results->Controls->Add(this->textBoxGP_resP);
			this->groupBoxGP_Results->Controls->Add(this->textBoxGP_resN);
			this->groupBoxGP_Results->Controls->Add(this->label1);
			this->groupBoxGP_Results->Controls->Add(this->label3);
			this->groupBoxGP_Results->Controls->Add(this->textBoxGP_resQ);
			this->groupBoxGP_Results->Controls->Add(this->label2);
			this->groupBoxGP_Results->Location = System::Drawing::Point(387, 53);
			this->groupBoxGP_Results->Name = L"groupBoxGP_Results";
			this->groupBoxGP_Results->Size = System::Drawing::Size(388, 142);
			this->groupBoxGP_Results->TabIndex = 11;
			this->groupBoxGP_Results->TabStop = false;
			this->groupBoxGP_Results->Text = L"Результаты";
			// 
			// radioButtonGP_N2
			// 
			this->radioButtonGP_N2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioButtonGP_N2->AutoSize = true;
			this->radioButtonGP_N2->Location = System::Drawing::Point(332, 33);
			this->radioButtonGP_N2->Name = L"radioButtonGP_N2";
			this->radioButtonGP_N2->Size = System::Drawing::Size(43, 17);
			this->radioButtonGP_N2->TabIndex = 19;
			this->radioButtonGP_N2->Text = L"л.с.";
			this->radioButtonGP_N2->UseVisualStyleBackColor = true;
			// 
			// radioButtonGP_N1
			// 
			this->radioButtonGP_N1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioButtonGP_N1->AutoSize = true;
			this->radioButtonGP_N1->Checked = true;
			this->radioButtonGP_N1->Location = System::Drawing::Point(287, 33);
			this->radioButtonGP_N1->Name = L"radioButtonGP_N1";
			this->radioButtonGP_N1->Size = System::Drawing::Size(43, 17);
			this->radioButtonGP_N1->TabIndex = 18;
			this->radioButtonGP_N1->TabStop = true;
			this->radioButtonGP_N1->Text = L"кВт";
			this->radioButtonGP_N1->UseVisualStyleBackColor = true;
			this->radioButtonGP_N1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButtonGP_N1_CheckedChanged);
			// 
			// textBoxGP_resP
			// 
			this->textBoxGP_resP->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxGP_resP->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxGP_resP->Location = System::Drawing::Point(113, 84);
			this->textBoxGP_resP->Name = L"textBoxGP_resP";
			this->textBoxGP_resP->ReadOnly = true;
			this->textBoxGP_resP->Size = System::Drawing::Size(260, 20);
			this->textBoxGP_resP->TabIndex = 17;
			this->textBoxGP_resP->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// textBoxGP_resN
			// 
			this->textBoxGP_resN->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxGP_resN->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxGP_resN->Location = System::Drawing::Point(113, 32);
			this->textBoxGP_resN->Name = L"textBoxGP_resN";
			this->textBoxGP_resN->ReadOnly = true;
			this->textBoxGP_resN->Size = System::Drawing::Size(168, 20);
			this->textBoxGP_resN->TabIndex = 13;
			this->textBoxGP_resN->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Давление (P), бар";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 35);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Мощность (N)";
			// 
			// textBoxGP_resQ
			// 
			this->textBoxGP_resQ->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxGP_resQ->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxGP_resQ->Location = System::Drawing::Point(113, 58);
			this->textBoxGP_resQ->Name = L"textBoxGP_resQ";
			this->textBoxGP_resQ->ReadOnly = true;
			this->textBoxGP_resQ->Size = System::Drawing::Size(260, 20);
			this->textBoxGP_resQ->TabIndex = 15;
			this->textBoxGP_resQ->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Расход (Q), л/мин";
			// 
			// buttonGP_Enter
			// 
			this->buttonGP_Enter->Location = System::Drawing::Point(15, 163);
			this->buttonGP_Enter->Name = L"buttonGP_Enter";
			this->buttonGP_Enter->Size = System::Drawing::Size(359, 32);
			this->buttonGP_Enter->TabIndex = 10;
			this->buttonGP_Enter->Text = L"Вычилсить";
			this->buttonGP_Enter->UseVisualStyleBackColor = true;
			this->buttonGP_Enter->Click += gcnew System::EventHandler(this, &MainForm::buttonGP_Enter_Click);
			// 
			// textBoxGP_eta
			// 
			this->textBoxGP_eta->Location = System::Drawing::Point(156, 137);
			this->textBoxGP_eta->MaxLength = 16;
			this->textBoxGP_eta->Name = L"textBoxGP_eta";
			this->textBoxGP_eta->Size = System::Drawing::Size(218, 20);
			this->textBoxGP_eta->TabIndex = 8;
			this->textBoxGP_eta->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelGP_eta
			// 
			this->labelGP_eta->AutoSize = true;
			this->labelGP_eta->Location = System::Drawing::Point(12, 140);
			this->labelGP_eta->Name = L"labelGP_eta";
			this->labelGP_eta->Size = System::Drawing::Size(124, 13);
			this->labelGP_eta->TabIndex = 7;
			this->labelGP_eta->Text = L"КПД насоса (0.85-0.99)";
			// 
			// textBoxGP_P
			// 
			this->textBoxGP_P->Location = System::Drawing::Point(156, 111);
			this->textBoxGP_P->MaxLength = 16;
			this->textBoxGP_P->Name = L"textBoxGP_P";
			this->textBoxGP_P->Size = System::Drawing::Size(218, 20);
			this->textBoxGP_P->TabIndex = 6;
			this->textBoxGP_P->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelGP_P
			// 
			this->labelGP_P->AutoSize = true;
			this->labelGP_P->Location = System::Drawing::Point(12, 114);
			this->labelGP_P->Name = L"labelGP_P";
			this->labelGP_P->Size = System::Drawing::Size(98, 13);
			this->labelGP_P->TabIndex = 5;
			this->labelGP_P->Text = L"Давление (P), бар";
			// 
			// textBoxGP_Q
			// 
			this->textBoxGP_Q->Location = System::Drawing::Point(156, 85);
			this->textBoxGP_Q->MaxLength = 16;
			this->textBoxGP_Q->Name = L"textBoxGP_Q";
			this->textBoxGP_Q->Size = System::Drawing::Size(218, 20);
			this->textBoxGP_Q->TabIndex = 4;
			this->textBoxGP_Q->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelGP_Q
			// 
			this->labelGP_Q->AutoSize = true;
			this->labelGP_Q->Location = System::Drawing::Point(12, 88);
			this->labelGP_Q->Name = L"labelGP_Q";
			this->labelGP_Q->Size = System::Drawing::Size(137, 13);
			this->labelGP_Q->TabIndex = 3;
			this->labelGP_Q->Text = L"Подача насоса (Q), л/мин";
			// 
			// textBoxGP_N
			// 
			this->textBoxGP_N->Location = System::Drawing::Point(156, 59);
			this->textBoxGP_N->MaxLength = 16;
			this->textBoxGP_N->Name = L"textBoxGP_N";
			this->textBoxGP_N->Size = System::Drawing::Size(218, 20);
			this->textBoxGP_N->TabIndex = 2;
			this->textBoxGP_N->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelGP_N
			// 
			this->labelGP_N->AutoSize = true;
			this->labelGP_N->Location = System::Drawing::Point(12, 62);
			this->labelGP_N->Name = L"labelGP_N";
			this->labelGP_N->Size = System::Drawing::Size(101, 13);
			this->labelGP_N->TabIndex = 1;
			this->labelGP_N->Text = L"Мощность (N), кВт";
			// 
			// labelGP_Header
			// 
			this->labelGP_Header->AutoSize = true;
			this->labelGP_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelGP_Header->Location = System::Drawing::Point(11, 14);
			this->labelGP_Header->Name = L"labelGP_Header";
			this->labelGP_Header->Size = System::Drawing::Size(543, 24);
			this->labelGP_Header->TabIndex = 0;
			this->labelGP_Header->Text = L"Расчет мощности, расхода и давления гидропривода";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBoxDT_info);
			this->tabPage2->Controls->Add(this->groupBoxDT_res);
			this->tabPage2->Controls->Add(this->buttonDT_Enter);
			this->tabPage2->Controls->Add(this->textBoxDT_Q);
			this->tabPage2->Controls->Add(this->labelDT_Q);
			this->tabPage2->Controls->Add(this->textBoxDT_V);
			this->tabPage2->Controls->Add(this->labelDT_V);
			this->tabPage2->Controls->Add(this->textBoxDT_D);
			this->tabPage2->Controls->Add(this->labelDT_D);
			this->tabPage2->Controls->Add(this->labelDT_Header);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(784, 559);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Расчет диаметра трубопровода, скорости потока";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// richTextBoxDT_info
			// 
			this->richTextBoxDT_info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxDT_info->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxDT_info->Location = System::Drawing::Point(15, 187);
			this->richTextBoxDT_info->Name = L"richTextBoxDT_info";
			this->richTextBoxDT_info->ReadOnly = true;
			this->richTextBoxDT_info->Size = System::Drawing::Size(760, 365);
			this->richTextBoxDT_info->TabIndex = 24;
			this->richTextBoxDT_info->Text = resources->GetString(L"richTextBoxDT_info.Text");
			// 
			// groupBoxDT_res
			// 
			this->groupBoxDT_res->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxDT_res->Controls->Add(this->textBoxDT_resV);
			this->groupBoxDT_res->Controls->Add(this->textBoxDT_resQ);
			this->groupBoxDT_res->Controls->Add(this->labelDT_resV);
			this->groupBoxDT_res->Controls->Add(this->labelDT_resQ);
			this->groupBoxDT_res->Controls->Add(this->textBoxDT_resD);
			this->groupBoxDT_res->Controls->Add(this->labelDT_resD);
			this->groupBoxDT_res->Location = System::Drawing::Point(387, 55);
			this->groupBoxDT_res->Name = L"groupBoxDT_res";
			this->groupBoxDT_res->Size = System::Drawing::Size(388, 117);
			this->groupBoxDT_res->TabIndex = 23;
			this->groupBoxDT_res->TabStop = false;
			this->groupBoxDT_res->Text = L"Результаты";
			// 
			// textBoxDT_resV
			// 
			this->textBoxDT_resV->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxDT_resV->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxDT_resV->Location = System::Drawing::Point(162, 84);
			this->textBoxDT_resV->Name = L"textBoxDT_resV";
			this->textBoxDT_resV->ReadOnly = true;
			this->textBoxDT_resV->Size = System::Drawing::Size(211, 20);
			this->textBoxDT_resV->TabIndex = 17;
			this->textBoxDT_resV->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// textBoxDT_resQ
			// 
			this->textBoxDT_resQ->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxDT_resQ->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxDT_resQ->Location = System::Drawing::Point(162, 32);
			this->textBoxDT_resQ->Name = L"textBoxDT_resQ";
			this->textBoxDT_resQ->ReadOnly = true;
			this->textBoxDT_resQ->Size = System::Drawing::Size(211, 20);
			this->textBoxDT_resQ->TabIndex = 13;
			this->textBoxDT_resQ->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelDT_resV
			// 
			this->labelDT_resV->AutoSize = true;
			this->labelDT_resV->Location = System::Drawing::Point(9, 87);
			this->labelDT_resV->Name = L"labelDT_resV";
			this->labelDT_resV->Size = System::Drawing::Size(145, 13);
			this->labelDT_resV->TabIndex = 16;
			this->labelDT_resV->Text = L"Скорость потока (v), м/сек";
			// 
			// labelDT_resQ
			// 
			this->labelDT_resQ->AutoSize = true;
			this->labelDT_resQ->Location = System::Drawing::Point(9, 35);
			this->labelDT_resQ->Name = L"labelDT_resQ";
			this->labelDT_resQ->Size = System::Drawing::Size(137, 13);
			this->labelDT_resQ->TabIndex = 12;
			this->labelDT_resQ->Text = L"Подача насоса (Q), л/мин";
			// 
			// textBoxDT_resD
			// 
			this->textBoxDT_resD->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxDT_resD->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxDT_resD->Location = System::Drawing::Point(162, 58);
			this->textBoxDT_resD->Name = L"textBoxDT_resD";
			this->textBoxDT_resD->ReadOnly = true;
			this->textBoxDT_resD->Size = System::Drawing::Size(211, 20);
			this->textBoxDT_resD->TabIndex = 15;
			this->textBoxDT_resD->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelDT_resD
			// 
			this->labelDT_resD->AutoSize = true;
			this->labelDT_resD->Location = System::Drawing::Point(9, 61);
			this->labelDT_resD->Name = L"labelDT_resD";
			this->labelDT_resD->Size = System::Drawing::Size(90, 13);
			this->labelDT_resD->TabIndex = 14;
			this->labelDT_resD->Text = L"Диаметр (d), мм";
			// 
			// buttonDT_Enter
			// 
			this->buttonDT_Enter->Location = System::Drawing::Point(15, 140);
			this->buttonDT_Enter->Name = L"buttonDT_Enter";
			this->buttonDT_Enter->Size = System::Drawing::Size(359, 32);
			this->buttonDT_Enter->TabIndex = 22;
			this->buttonDT_Enter->Text = L"Вычилсить";
			this->buttonDT_Enter->UseVisualStyleBackColor = true;
			this->buttonDT_Enter->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// textBoxDT_Q
			// 
			this->textBoxDT_Q->Location = System::Drawing::Point(168, 113);
			this->textBoxDT_Q->MaxLength = 16;
			this->textBoxDT_Q->Name = L"textBoxDT_Q";
			this->textBoxDT_Q->Size = System::Drawing::Size(206, 20);
			this->textBoxDT_Q->TabIndex = 19;
			this->textBoxDT_Q->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelDT_Q
			// 
			this->labelDT_Q->AutoSize = true;
			this->labelDT_Q->Location = System::Drawing::Point(12, 116);
			this->labelDT_Q->Name = L"labelDT_Q";
			this->labelDT_Q->Size = System::Drawing::Size(137, 13);
			this->labelDT_Q->TabIndex = 18;
			this->labelDT_Q->Text = L"Подача насоса (Q), л/мин";
			// 
			// textBoxDT_V
			// 
			this->textBoxDT_V->Location = System::Drawing::Point(168, 87);
			this->textBoxDT_V->MaxLength = 16;
			this->textBoxDT_V->Name = L"textBoxDT_V";
			this->textBoxDT_V->Size = System::Drawing::Size(206, 20);
			this->textBoxDT_V->TabIndex = 17;
			this->textBoxDT_V->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelDT_V
			// 
			this->labelDT_V->AutoSize = true;
			this->labelDT_V->Location = System::Drawing::Point(12, 90);
			this->labelDT_V->Name = L"labelDT_V";
			this->labelDT_V->Size = System::Drawing::Size(145, 13);
			this->labelDT_V->TabIndex = 16;
			this->labelDT_V->Text = L"Скорость потока (v), м/сек";
			// 
			// textBoxDT_D
			// 
			this->textBoxDT_D->Location = System::Drawing::Point(168, 61);
			this->textBoxDT_D->MaxLength = 16;
			this->textBoxDT_D->Name = L"textBoxDT_D";
			this->textBoxDT_D->Size = System::Drawing::Size(206, 20);
			this->textBoxDT_D->TabIndex = 15;
			this->textBoxDT_D->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelDT_D
			// 
			this->labelDT_D->AutoSize = true;
			this->labelDT_D->Location = System::Drawing::Point(12, 64);
			this->labelDT_D->Name = L"labelDT_D";
			this->labelDT_D->Size = System::Drawing::Size(90, 13);
			this->labelDT_D->TabIndex = 14;
			this->labelDT_D->Text = L"Диаметр (d), мм";
			// 
			// labelDT_Header
			// 
			this->labelDT_Header->AutoSize = true;
			this->labelDT_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDT_Header->Location = System::Drawing::Point(11, 12);
			this->labelDT_Header->Name = L"labelDT_Header";
			this->labelDT_Header->Size = System::Drawing::Size(505, 24);
			this->labelDT_Header->TabIndex = 13;
			this->labelDT_Header->Text = L"Расчет диаметра трубопровода, скорости потока";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->textBoxPG_V);
			this->tabPage3->Controls->Add(this->labelPG_V);
			this->tabPage3->Controls->Add(this->textBoxPG_P);
			this->tabPage3->Controls->Add(this->labelPG_P);
			this->tabPage3->Controls->Add(this->richTextBoxPG_info);
			this->tabPage3->Controls->Add(this->groupBoxPG_res);
			this->tabPage3->Controls->Add(this->buttonPG_Enter);
			this->tabPage3->Controls->Add(this->textBoxPG_LSh);
			this->tabPage3->Controls->Add(this->labelPG_LSh);
			this->tabPage3->Controls->Add(this->textBoxBG_DSh);
			this->tabPage3->Controls->Add(this->labelPG_DSh);
			this->tabPage3->Controls->Add(this->textBoxPG_DP);
			this->tabPage3->Controls->Add(this->labelPG_DP);
			this->tabPage3->Controls->Add(this->textBoxPG_n);
			this->tabPage3->Controls->Add(this->labelPG_n);
			this->tabPage3->Controls->Add(this->labelPG_Header);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(784, 559);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Расчет параметров гидроцилиндра по его размерам";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// textBoxPG_V
			// 
			this->textBoxPG_V->Location = System::Drawing::Point(156, 191);
			this->textBoxPG_V->MaxLength = 16;
			this->textBoxPG_V->Name = L"textBoxPG_V";
			this->textBoxPG_V->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_V->TabIndex = 20;
			this->textBoxPG_V->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelPG_V
			// 
			this->labelPG_V->AutoSize = true;
			this->labelPG_V->Location = System::Drawing::Point(12, 194);
			this->labelPG_V->Name = L"labelPG_V";
			this->labelPG_V->Size = System::Drawing::Size(132, 13);
			this->labelPG_V->TabIndex = 27;
			this->labelPG_V->Text = L"Скорость хода(v), м/мин";
			// 
			// textBoxPG_P
			// 
			this->textBoxPG_P->Location = System::Drawing::Point(156, 165);
			this->textBoxPG_P->MaxLength = 16;
			this->textBoxPG_P->Name = L"textBoxPG_P";
			this->textBoxPG_P->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_P->TabIndex = 19;
			this->textBoxPG_P->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelPG_P
			// 
			this->labelPG_P->AutoSize = true;
			this->labelPG_P->Location = System::Drawing::Point(12, 168);
			this->labelPG_P->Name = L"labelPG_P";
			this->labelPG_P->Size = System::Drawing::Size(137, 13);
			this->labelPG_P->TabIndex = 25;
			this->labelPG_P->Text = L"Рабочее давление(P), бар\t";
			// 
			// richTextBoxPG_info
			// 
			this->richTextBoxPG_info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxPG_info->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxPG_info->Location = System::Drawing::Point(385, 61);
			this->richTextBoxPG_info->Name = L"richTextBoxPG_info";
			this->richTextBoxPG_info->ReadOnly = true;
			this->richTextBoxPG_info->Size = System::Drawing::Size(391, 188);
			this->richTextBoxPG_info->TabIndex = 24;
			this->richTextBoxPG_info->Text = resources->GetString(L"richTextBoxPG_info.Text");
			// 
			// groupBoxPG_res
			// 
			this->groupBoxPG_res->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_SumFVt);
			this->groupBoxPG_res->Controls->Add(this->labelPG_SumFVt);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_SumFV);
			this->groupBoxPG_res->Controls->Add(this->labelPG_SumFV);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_NVC);
			this->groupBoxPG_res->Controls->Add(this->labelPG_NVC);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_DQPShP);
			this->groupBoxPG_res->Controls->Add(this->labelPG_DQPShP);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_FVtSh);
			this->groupBoxPG_res->Controls->Add(this->labelPG_FVtSh);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_FShC);
			this->groupBoxPG_res->Controls->Add(this->labelPG_FShC);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_NVtSh);
			this->groupBoxPG_res->Controls->Add(this->labelPG_NVtSh);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_QPP);
			this->groupBoxPG_res->Controls->Add(this->labelPG_QPP);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_QVSh);
			this->groupBoxPG_res->Controls->Add(this->labelPG_QVSh);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_CVShP);
			this->groupBoxPG_res->Controls->Add(this->labelPG_CVShP);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_VShP);
			this->groupBoxPG_res->Controls->Add(this->labelPG_VShP);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_CVPP);
			this->groupBoxPG_res->Controls->Add(this->labelPG_CVPP);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_VPP);
			this->groupBoxPG_res->Controls->Add(this->labelPG_VPP);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_SK);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_SP);
			this->groupBoxPG_res->Controls->Add(this->labelPG_SK);
			this->groupBoxPG_res->Controls->Add(this->labelPG_SP);
			this->groupBoxPG_res->Controls->Add(this->textBoxPG_SSh);
			this->groupBoxPG_res->Controls->Add(this->labelPG_SSh);
			this->groupBoxPG_res->Location = System::Drawing::Point(15, 255);
			this->groupBoxPG_res->Name = L"groupBoxPG_res";
			this->groupBoxPG_res->Size = System::Drawing::Size(761, 294);
			this->groupBoxPG_res->TabIndex = 23;
			this->groupBoxPG_res->TabStop = false;
			this->groupBoxPG_res->Text = L"Результаты";
			// 
			// textBoxPG_SumFVt
			// 
			this->textBoxPG_SumFVt->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_SumFVt->Location = System::Drawing::Point(528, 223);
			this->textBoxPG_SumFVt->Name = L"textBoxPG_SumFVt";
			this->textBoxPG_SumFVt->ReadOnly = true;
			this->textBoxPG_SumFVt->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_SumFVt->TabIndex = 35;
			this->textBoxPG_SumFVt->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_SumFVt
			// 
			this->labelPG_SumFVt->AutoSize = true;
			this->labelPG_SumFVt->Location = System::Drawing::Point(367, 220);
			this->labelPG_SumFVt->Name = L"labelPG_SumFVt";
			this->labelPG_SumFVt->Size = System::Drawing::Size(103, 26);
			this->labelPG_SumFVt->TabIndex = 42;
			this->labelPG_SumFVt->Text = L"Суммарное усилие\r\nвыталкивания, кг";
			// 
			// textBoxPG_SumFV
			// 
			this->textBoxPG_SumFV->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_SumFV->Location = System::Drawing::Point(528, 257);
			this->textBoxPG_SumFV->Name = L"textBoxPG_SumFV";
			this->textBoxPG_SumFV->ReadOnly = true;
			this->textBoxPG_SumFV->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_SumFV->TabIndex = 37;
			this->textBoxPG_SumFV->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_SumFV
			// 
			this->labelPG_SumFV->AutoSize = true;
			this->labelPG_SumFV->Location = System::Drawing::Point(367, 254);
			this->labelPG_SumFV->Name = L"labelPG_SumFV";
			this->labelPG_SumFV->Size = System::Drawing::Size(103, 26);
			this->labelPG_SumFV->TabIndex = 40;
			this->labelPG_SumFV->Text = L"Суммарное усилие\r\nвтягивания, кг";
			// 
			// textBoxPG_NVC
			// 
			this->textBoxPG_NVC->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_NVC->Location = System::Drawing::Point(528, 189);
			this->textBoxPG_NVC->Name = L"textBoxPG_NVC";
			this->textBoxPG_NVC->ReadOnly = true;
			this->textBoxPG_NVC->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_NVC->TabIndex = 33;
			this->textBoxPG_NVC->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_NVC
			// 
			this->labelPG_NVC->AutoSize = true;
			this->labelPG_NVC->Location = System::Drawing::Point(367, 186);
			this->labelPG_NVC->Name = L"labelPG_NVC";
			this->labelPG_NVC->Size = System::Drawing::Size(136, 26);
			this->labelPG_NVC->TabIndex = 38;
			this->labelPG_NVC->Text = L"Мощность выталкивания\r\nштока цилиндра, кВт";
			// 
			// textBoxPG_DQPShP
			// 
			this->textBoxPG_DQPShP->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_DQPShP->Location = System::Drawing::Point(528, 155);
			this->textBoxPG_DQPShP->Name = L"textBoxPG_DQPShP";
			this->textBoxPG_DQPShP->ReadOnly = true;
			this->textBoxPG_DQPShP->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_DQPShP->TabIndex = 31;
			this->textBoxPG_DQPShP->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_DQPShP
			// 
			this->labelPG_DQPShP->AutoSize = true;
			this->labelPG_DQPShP->Location = System::Drawing::Point(367, 152);
			this->labelPG_DQPShP->Name = L"labelPG_DQPShP";
			this->labelPG_DQPShP->Size = System::Drawing::Size(153, 26);
			this->labelPG_DQPShP->TabIndex = 36;
			this->labelPG_DQPShP->Text = L"Разница расхода поршневой\r\nи штоковой полостей, л/мин";
			// 
			// textBoxPG_FVtSh
			// 
			this->textBoxPG_FVtSh->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_FVtSh->Location = System::Drawing::Point(141, 257);
			this->textBoxPG_FVtSh->Name = L"textBoxPG_FVtSh";
			this->textBoxPG_FVtSh->ReadOnly = true;
			this->textBoxPG_FVtSh->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_FVtSh->TabIndex = 36;
			this->textBoxPG_FVtSh->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_FVtSh
			// 
			this->labelPG_FVtSh->AutoSize = true;
			this->labelPG_FVtSh->Location = System::Drawing::Point(9, 254);
			this->labelPG_FVtSh->Name = L"labelPG_FVtSh";
			this->labelPG_FVtSh->Size = System::Drawing::Size(106, 26);
			this->labelPG_FVtSh->TabIndex = 34;
			this->labelPG_FVtSh->Text = L"Усилие втягивания\r\nштока цилиндра, кг";
			// 
			// textBoxPG_FShC
			// 
			this->textBoxPG_FShC->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_FShC->Location = System::Drawing::Point(141, 223);
			this->textBoxPG_FShC->Name = L"textBoxPG_FShC";
			this->textBoxPG_FShC->ReadOnly = true;
			this->textBoxPG_FShC->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_FShC->TabIndex = 34;
			this->textBoxPG_FShC->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_FShC
			// 
			this->labelPG_FShC->AutoSize = true;
			this->labelPG_FShC->Location = System::Drawing::Point(9, 220);
			this->labelPG_FShC->Name = L"labelPG_FShC";
			this->labelPG_FShC->Size = System::Drawing::Size(121, 26);
			this->labelPG_FShC->TabIndex = 32;
			this->labelPG_FShC->Text = L"Усилие выталкивания\r\nштока цилиндра, кг";
			// 
			// textBoxPG_NVtSh
			// 
			this->textBoxPG_NVtSh->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_NVtSh->Location = System::Drawing::Point(141, 189);
			this->textBoxPG_NVtSh->Name = L"textBoxPG_NVtSh";
			this->textBoxPG_NVtSh->ReadOnly = true;
			this->textBoxPG_NVtSh->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_NVtSh->TabIndex = 32;
			this->textBoxPG_NVtSh->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_NVtSh
			// 
			this->labelPG_NVtSh->AutoSize = true;
			this->labelPG_NVtSh->Location = System::Drawing::Point(9, 186);
			this->labelPG_NVtSh->Name = L"labelPG_NVtSh";
			this->labelPG_NVtSh->Size = System::Drawing::Size(121, 26);
			this->labelPG_NVtSh->TabIndex = 30;
			this->labelPG_NVtSh->Text = L"Мощность втягивания\r\nштока, кВт";
			// 
			// textBoxPG_QPP
			// 
			this->textBoxPG_QPP->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_QPP->Location = System::Drawing::Point(141, 155);
			this->textBoxPG_QPP->Name = L"textBoxPG_QPP";
			this->textBoxPG_QPP->ReadOnly = true;
			this->textBoxPG_QPP->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_QPP->TabIndex = 30;
			this->textBoxPG_QPP->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_QPP
			// 
			this->labelPG_QPP->AutoSize = true;
			this->labelPG_QPP->Location = System::Drawing::Point(9, 152);
			this->labelPG_QPP->Name = L"labelPG_QPP";
			this->labelPG_QPP->Size = System::Drawing::Size(111, 26);
			this->labelPG_QPP->TabIndex = 28;
			this->labelPG_QPP->Text = L"Расход в поршневой\r\nполости, л/мин";
			// 
			// textBoxPG_QVSh
			// 
			this->textBoxPG_QVSh->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_QVSh->Location = System::Drawing::Point(528, 121);
			this->textBoxPG_QVSh->Name = L"textBoxPG_QVSh";
			this->textBoxPG_QVSh->ReadOnly = true;
			this->textBoxPG_QVSh->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_QVSh->TabIndex = 29;
			this->textBoxPG_QVSh->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_QVSh
			// 
			this->labelPG_QVSh->AutoSize = true;
			this->labelPG_QVSh->Location = System::Drawing::Point(367, 116);
			this->labelPG_QVSh->Name = L"labelPG_QVSh";
			this->labelPG_QVSh->Size = System::Drawing::Size(125, 26);
			this->labelPG_QVSh->TabIndex = 26;
			this->labelPG_QVSh->Text = L"Расход при втягивании\r\nштока, л/мин";
			// 
			// textBoxPG_CVShP
			// 
			this->textBoxPG_CVShP->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_CVShP->Location = System::Drawing::Point(141, 121);
			this->textBoxPG_CVShP->Name = L"textBoxPG_CVShP";
			this->textBoxPG_CVShP->ReadOnly = true;
			this->textBoxPG_CVShP->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_CVShP->TabIndex = 28;
			this->textBoxPG_CVShP->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_CVShP
			// 
			this->labelPG_CVShP->AutoSize = true;
			this->labelPG_CVShP->Location = System::Drawing::Point(9, 116);
			this->labelPG_CVShP->Name = L"labelPG_CVShP";
			this->labelPG_CVShP->Size = System::Drawing::Size(112, 26);
			this->labelPG_CVShP->TabIndex = 24;
			this->labelPG_CVShP->Text = L"Общий объем\r\nштоковой полости, л";
			// 
			// textBoxPG_VShP
			// 
			this->textBoxPG_VShP->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_VShP->Location = System::Drawing::Point(528, 87);
			this->textBoxPG_VShP->Name = L"textBoxPG_VShP";
			this->textBoxPG_VShP->ReadOnly = true;
			this->textBoxPG_VShP->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_VShP->TabIndex = 27;
			this->textBoxPG_VShP->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_VShP
			// 
			this->labelPG_VShP->AutoSize = true;
			this->labelPG_VShP->Location = System::Drawing::Point(367, 90);
			this->labelPG_VShP->Name = L"labelPG_VShP";
			this->labelPG_VShP->Size = System::Drawing::Size(150, 13);
			this->labelPG_VShP->TabIndex = 22;
			this->labelPG_VShP->Text = L"Объем штоковой полости, л";
			// 
			// textBoxPG_CVPP
			// 
			this->textBoxPG_CVPP->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_CVPP->Location = System::Drawing::Point(141, 87);
			this->textBoxPG_CVPP->Name = L"textBoxPG_CVPP";
			this->textBoxPG_CVPP->ReadOnly = true;
			this->textBoxPG_CVPP->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_CVPP->TabIndex = 26;
			this->textBoxPG_CVPP->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_CVPP
			// 
			this->labelPG_CVPP->AutoSize = true;
			this->labelPG_CVPP->Location = System::Drawing::Point(9, 84);
			this->labelPG_CVPP->Name = L"labelPG_CVPP";
			this->labelPG_CVPP->Size = System::Drawing::Size(119, 26);
			this->labelPG_CVPP->TabIndex = 20;
			this->labelPG_CVPP->Text = L"Общий объем\r\nпоршневой полости, л";
			// 
			// textBoxPG_VPP
			// 
			this->textBoxPG_VPP->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_VPP->Location = System::Drawing::Point(528, 53);
			this->textBoxPG_VPP->Name = L"textBoxPG_VPP";
			this->textBoxPG_VPP->ReadOnly = true;
			this->textBoxPG_VPP->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_VPP->TabIndex = 25;
			this->textBoxPG_VPP->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_VPP
			// 
			this->labelPG_VPP->AutoSize = true;
			this->labelPG_VPP->Location = System::Drawing::Point(367, 56);
			this->labelPG_VPP->Name = L"labelPG_VPP";
			this->labelPG_VPP->Size = System::Drawing::Size(157, 13);
			this->labelPG_VPP->TabIndex = 18;
			this->labelPG_VPP->Text = L"Объем поршневой полости, л";
			// 
			// textBoxPG_SK
			// 
			this->textBoxPG_SK->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_SK->Location = System::Drawing::Point(141, 53);
			this->textBoxPG_SK->Name = L"textBoxPG_SK";
			this->textBoxPG_SK->ReadOnly = true;
			this->textBoxPG_SK->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_SK->TabIndex = 24;
			this->textBoxPG_SK->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// textBoxPG_SP
			// 
			this->textBoxPG_SP->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_SP->Location = System::Drawing::Point(141, 19);
			this->textBoxPG_SP->Name = L"textBoxPG_SP";
			this->textBoxPG_SP->ReadOnly = true;
			this->textBoxPG_SP->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_SP->TabIndex = 22;
			this->textBoxPG_SP->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_SK
			// 
			this->labelPG_SK->AutoSize = true;
			this->labelPG_SK->Location = System::Drawing::Point(9, 49);
			this->labelPG_SK->Name = L"labelPG_SK";
			this->labelPG_SK->Size = System::Drawing::Size(108, 26);
			this->labelPG_SK->TabIndex = 16;
			this->labelPG_SK->Text = L"Площадь кольца\r\n(шток. полость), см²";
			// 
			// labelPG_SP
			// 
			this->labelPG_SP->AutoSize = true;
			this->labelPG_SP->Location = System::Drawing::Point(9, 22);
			this->labelPG_SP->Name = L"labelPG_SP";
			this->labelPG_SP->Size = System::Drawing::Size(118, 13);
			this->labelPG_SP->TabIndex = 12;
			this->labelPG_SP->Text = L"Площадь поршня, см²";
			// 
			// textBoxPG_SSh
			// 
			this->textBoxPG_SSh->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPG_SSh->Location = System::Drawing::Point(528, 19);
			this->textBoxPG_SSh->Name = L"textBoxPG_SSh";
			this->textBoxPG_SSh->ReadOnly = true;
			this->textBoxPG_SSh->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_SSh->TabIndex = 23;
			this->textBoxPG_SSh->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPG_SSh
			// 
			this->labelPG_SSh->AutoSize = true;
			this->labelPG_SSh->Location = System::Drawing::Point(367, 22);
			this->labelPG_SSh->Name = L"labelPG_SSh";
			this->labelPG_SSh->Size = System::Drawing::Size(111, 13);
			this->labelPG_SSh->TabIndex = 14;
			this->labelPG_SSh->Text = L"Площадь штока, см²";
			// 
			// buttonPG_Enter
			// 
			this->buttonPG_Enter->Location = System::Drawing::Point(15, 217);
			this->buttonPG_Enter->Name = L"buttonPG_Enter";
			this->buttonPG_Enter->Size = System::Drawing::Size(359, 32);
			this->buttonPG_Enter->TabIndex = 21;
			this->buttonPG_Enter->Text = L"Вычилсить";
			this->buttonPG_Enter->UseVisualStyleBackColor = true;
			this->buttonPG_Enter->Click += gcnew System::EventHandler(this, &MainForm::buttonPG_Enter_Click);
			// 
			// textBoxPG_LSh
			// 
			this->textBoxPG_LSh->Location = System::Drawing::Point(156, 139);
			this->textBoxPG_LSh->MaxLength = 16;
			this->textBoxPG_LSh->Name = L"textBoxPG_LSh";
			this->textBoxPG_LSh->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_LSh->TabIndex = 18;
			this->textBoxPG_LSh->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelPG_LSh
			// 
			this->labelPG_LSh->AutoSize = true;
			this->labelPG_LSh->Location = System::Drawing::Point(12, 142);
			this->labelPG_LSh->Name = L"labelPG_LSh";
			this->labelPG_LSh->Size = System::Drawing::Size(97, 13);
			this->labelPG_LSh->TabIndex = 20;
			this->labelPG_LSh->Text = L"Ход штока (L), мм";
			// 
			// textBoxBG_DSh
			// 
			this->textBoxBG_DSh->Location = System::Drawing::Point(156, 113);
			this->textBoxBG_DSh->MaxLength = 16;
			this->textBoxBG_DSh->Name = L"textBoxBG_DSh";
			this->textBoxBG_DSh->Size = System::Drawing::Size(218, 20);
			this->textBoxBG_DSh->TabIndex = 17;
			this->textBoxBG_DSh->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelPG_DSh
			// 
			this->labelPG_DSh->AutoSize = true;
			this->labelPG_DSh->Location = System::Drawing::Point(12, 116);
			this->labelPG_DSh->Name = L"labelPG_DSh";
			this->labelPG_DSh->Size = System::Drawing::Size(109, 13);
			this->labelPG_DSh->TabIndex = 18;
			this->labelPG_DSh->Text = L"Диаметр штока, мм";
			// 
			// textBoxPG_DP
			// 
			this->textBoxPG_DP->Location = System::Drawing::Point(156, 87);
			this->textBoxPG_DP->MaxLength = 16;
			this->textBoxPG_DP->Name = L"textBoxPG_DP";
			this->textBoxPG_DP->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_DP->TabIndex = 16;
			this->textBoxPG_DP->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelPG_DP
			// 
			this->labelPG_DP->AutoSize = true;
			this->labelPG_DP->Location = System::Drawing::Point(12, 90);
			this->labelPG_DP->Name = L"labelPG_DP";
			this->labelPG_DP->Size = System::Drawing::Size(116, 13);
			this->labelPG_DP->TabIndex = 16;
			this->labelPG_DP->Text = L"Диаметр поршня, мм";
			// 
			// textBoxPG_n
			// 
			this->textBoxPG_n->Location = System::Drawing::Point(156, 61);
			this->textBoxPG_n->MaxLength = 16;
			this->textBoxPG_n->Name = L"textBoxPG_n";
			this->textBoxPG_n->Size = System::Drawing::Size(218, 20);
			this->textBoxPG_n->TabIndex = 15;
			this->textBoxPG_n->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelPG_n
			// 
			this->labelPG_n->AutoSize = true;
			this->labelPG_n->Location = System::Drawing::Point(12, 64);
			this->labelPG_n->Name = L"labelPG_n";
			this->labelPG_n->Size = System::Drawing::Size(138, 13);
			this->labelPG_n->TabIndex = 14;
			this->labelPG_n->Text = L"Количество цилиндров (n)";
			// 
			// labelPG_Header
			// 
			this->labelPG_Header->AutoSize = true;
			this->labelPG_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPG_Header->Location = System::Drawing::Point(11, 15);
			this->labelPG_Header->Name = L"labelPG_Header";
			this->labelPG_Header->Size = System::Drawing::Size(537, 24);
			this->labelPG_Header->TabIndex = 13;
			this->labelPG_Header->Text = L"Расчет параметров гидроцилиндра по его размерам";
			// 
			// tabPageRG
			// 
			this->tabPageRG->Controls->Add(this->textBoxRG_Sp);
			this->tabPageRG->Controls->Add(this->labelRG_Sp);
			this->tabPageRG->Controls->Add(this->textBoxRG_t);
			this->tabPageRG->Controls->Add(this->labelRG_t);
			this->tabPageRG->Controls->Add(this->textBoxRG_L);
			this->tabPageRG->Controls->Add(this->labelRG_L);
			this->tabPageRG->Controls->Add(this->richTextBoxRG_Info);
			this->tabPageRG->Controls->Add(this->groupBoxRG_res);
			this->tabPageRG->Controls->Add(this->buttonRG_Enter);
			this->tabPageRG->Controls->Add(this->textBoxRG_fi);
			this->tabPageRG->Controls->Add(this->labelRG_fi);
			this->tabPageRG->Controls->Add(this->textBoxRG_P);
			this->tabPageRG->Controls->Add(this->labelRG_P);
			this->tabPageRG->Controls->Add(this->textBoxRG_n);
			this->tabPageRG->Controls->Add(this->labelRG_n);
			this->tabPageRG->Controls->Add(this->textBoxRG_Fst);
			this->tabPageRG->Controls->Add(this->labelRG_Fst);
			this->tabPageRG->Controls->Add(this->labelRG);
			this->tabPageRG->Location = System::Drawing::Point(4, 22);
			this->tabPageRG->Name = L"tabPageRG";
			this->tabPageRG->Padding = System::Windows::Forms::Padding(3);
			this->tabPageRG->Size = System::Drawing::Size(784, 559);
			this->tabPageRG->TabIndex = 3;
			this->tabPageRG->Text = L"Расчет размеров гидроцилиндра по техническим параметрам";
			this->tabPageRG->UseVisualStyleBackColor = true;
			// 
			// textBoxRG_Sp
			// 
			this->textBoxRG_Sp->Location = System::Drawing::Point(199, 218);
			this->textBoxRG_Sp->MaxLength = 16;
			this->textBoxRG_Sp->Name = L"textBoxRG_Sp";
			this->textBoxRG_Sp->Size = System::Drawing::Size(175, 20);
			this->textBoxRG_Sp->TabIndex = 21;
			this->textBoxRG_Sp->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelRG_Sp
			// 
			this->labelRG_Sp->AutoSize = true;
			this->labelRG_Sp->Location = System::Drawing::Point(12, 221);
			this->labelRG_Sp->Name = L"labelRG_Sp";
			this->labelRG_Sp->Size = System::Drawing::Size(140, 13);
			this->labelRG_Sp->TabIndex = 29;
			this->labelRG_Sp->Text = L"Площадь поршня (Sp), см²";
			// 
			// textBoxRG_t
			// 
			this->textBoxRG_t->Location = System::Drawing::Point(199, 192);
			this->textBoxRG_t->MaxLength = 16;
			this->textBoxRG_t->Name = L"textBoxRG_t";
			this->textBoxRG_t->Size = System::Drawing::Size(175, 20);
			this->textBoxRG_t->TabIndex = 20;
			this->textBoxRG_t->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelRG_t
			// 
			this->labelRG_t->AutoSize = true;
			this->labelRG_t->Location = System::Drawing::Point(12, 195);
			this->labelRG_t->Name = L"labelRG_t";
			this->labelRG_t->Size = System::Drawing::Size(146, 13);
			this->labelRG_t->TabIndex = 27;
			this->labelRG_t->Text = L"Время выдвижения (t), сек.";
			// 
			// textBoxRG_L
			// 
			this->textBoxRG_L->Location = System::Drawing::Point(199, 166);
			this->textBoxRG_L->MaxLength = 16;
			this->textBoxRG_L->Name = L"textBoxRG_L";
			this->textBoxRG_L->Size = System::Drawing::Size(175, 20);
			this->textBoxRG_L->TabIndex = 19;
			this->textBoxRG_L->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelRG_L
			// 
			this->labelRG_L->AutoSize = true;
			this->labelRG_L->Location = System::Drawing::Point(12, 169);
			this->labelRG_L->Name = L"labelRG_L";
			this->labelRG_L->Size = System::Drawing::Size(103, 13);
			this->labelRG_L->TabIndex = 25;
			this->labelRG_L->Text = L"Длина хода (L), мм";
			// 
			// richTextBoxRG_Info
			// 
			this->richTextBoxRG_Info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxRG_Info->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxRG_Info->Location = System::Drawing::Point(15, 292);
			this->richTextBoxRG_Info->Name = L"richTextBoxRG_Info";
			this->richTextBoxRG_Info->ReadOnly = true;
			this->richTextBoxRG_Info->Size = System::Drawing::Size(760, 260);
			this->richTextBoxRG_Info->TabIndex = 24;
			this->richTextBoxRG_Info->Text = L"Здесь Вы можете вычислить геометрический размер цилиндра, зная необходимое усилие"
				L" и рабочее давление гидроситемы.";
			// 
			// groupBoxRG_res
			// 
			this->groupBoxRG_res->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxRG_res->Controls->Add(this->textBoxRG_resv);
			this->groupBoxRG_res->Controls->Add(this->labelRG_resv);
			this->groupBoxRG_res->Controls->Add(this->textBoxRG_resfi);
			this->groupBoxRG_res->Controls->Add(this->textBoxRG_resSp);
			this->groupBoxRG_res->Controls->Add(this->labelRG_resfi);
			this->groupBoxRG_res->Controls->Add(this->labelRG_resSp);
			this->groupBoxRG_res->Controls->Add(this->textBoxRG_resP);
			this->groupBoxRG_res->Controls->Add(this->labelRG_resP);
			this->groupBoxRG_res->Location = System::Drawing::Point(387, 56);
			this->groupBoxRG_res->Name = L"groupBoxRG_res";
			this->groupBoxRG_res->Size = System::Drawing::Size(388, 220);
			this->groupBoxRG_res->TabIndex = 23;
			this->groupBoxRG_res->TabStop = false;
			this->groupBoxRG_res->Text = L"Результаты";
			// 
			// textBoxRG_resv
			// 
			this->textBoxRG_resv->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxRG_resv->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxRG_resv->Location = System::Drawing::Point(219, 110);
			this->textBoxRG_resv->Name = L"textBoxRG_resv";
			this->textBoxRG_resv->ReadOnly = true;
			this->textBoxRG_resv->Size = System::Drawing::Size(154, 20);
			this->textBoxRG_resv->TabIndex = 26;
			this->textBoxRG_resv->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelRG_resv
			// 
			this->labelRG_resv->AutoSize = true;
			this->labelRG_resv->Location = System::Drawing::Point(9, 113);
			this->labelRG_resv->Name = L"labelRG_resv";
			this->labelRG_resv->Size = System::Drawing::Size(204, 13);
			this->labelRG_resv->TabIndex = 18;
			this->labelRG_resv->Text = L"Скорость выдвижения штока (v), мм/с";
			// 
			// textBoxRG_resfi
			// 
			this->textBoxRG_resfi->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxRG_resfi->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxRG_resfi->Location = System::Drawing::Point(219, 84);
			this->textBoxRG_resfi->Name = L"textBoxRG_resfi";
			this->textBoxRG_resfi->ReadOnly = true;
			this->textBoxRG_resfi->Size = System::Drawing::Size(154, 20);
			this->textBoxRG_resfi->TabIndex = 25;
			this->textBoxRG_resfi->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// textBoxRG_resSp
			// 
			this->textBoxRG_resSp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxRG_resSp->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxRG_resSp->Location = System::Drawing::Point(219, 32);
			this->textBoxRG_resSp->Name = L"textBoxRG_resSp";
			this->textBoxRG_resSp->ReadOnly = true;
			this->textBoxRG_resSp->Size = System::Drawing::Size(154, 20);
			this->textBoxRG_resSp->TabIndex = 23;
			this->textBoxRG_resSp->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelRG_resfi
			// 
			this->labelRG_resfi->AutoSize = true;
			this->labelRG_resfi->Location = System::Drawing::Point(9, 87);
			this->labelRG_resfi->Name = L"labelRG_resfi";
			this->labelRG_resfi->Size = System::Drawing::Size(181, 13);
			this->labelRG_resfi->TabIndex = 16;
			this->labelRG_resfi->Text = L"Диаметр поршня цилиндра (fi), мм";
			// 
			// labelRG_resSp
			// 
			this->labelRG_resSp->AutoSize = true;
			this->labelRG_resSp->Location = System::Drawing::Point(9, 35);
			this->labelRG_resSp->Name = L"labelRG_resSp";
			this->labelRG_resSp->Size = System::Drawing::Size(140, 13);
			this->labelRG_resSp->TabIndex = 12;
			this->labelRG_resSp->Text = L"Площадь поршня (Sp), см²";
			// 
			// textBoxRG_resP
			// 
			this->textBoxRG_resP->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxRG_resP->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxRG_resP->Location = System::Drawing::Point(219, 58);
			this->textBoxRG_resP->Name = L"textBoxRG_resP";
			this->textBoxRG_resP->ReadOnly = true;
			this->textBoxRG_resP->Size = System::Drawing::Size(154, 20);
			this->textBoxRG_resP->TabIndex = 24;
			this->textBoxRG_resP->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelRG_resP
			// 
			this->labelRG_resP->AutoSize = true;
			this->labelRG_resP->Location = System::Drawing::Point(9, 61);
			this->labelRG_resP->Name = L"labelRG_resP";
			this->labelRG_resP->Size = System::Drawing::Size(98, 13);
			this->labelRG_resP->TabIndex = 14;
			this->labelRG_resP->Text = L"Давление (P), бар";
			// 
			// buttonRG_Enter
			// 
			this->buttonRG_Enter->Location = System::Drawing::Point(15, 244);
			this->buttonRG_Enter->Name = L"buttonRG_Enter";
			this->buttonRG_Enter->Size = System::Drawing::Size(359, 32);
			this->buttonRG_Enter->TabIndex = 22;
			this->buttonRG_Enter->Text = L"Вычилсить";
			this->buttonRG_Enter->UseVisualStyleBackColor = true;
			this->buttonRG_Enter->Click += gcnew System::EventHandler(this, &MainForm::buttonRG_Enter_Click);
			// 
			// textBoxRG_fi
			// 
			this->textBoxRG_fi->Location = System::Drawing::Point(199, 140);
			this->textBoxRG_fi->MaxLength = 16;
			this->textBoxRG_fi->Name = L"textBoxRG_fi";
			this->textBoxRG_fi->Size = System::Drawing::Size(175, 20);
			this->textBoxRG_fi->TabIndex = 18;
			this->textBoxRG_fi->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelRG_fi
			// 
			this->labelRG_fi->AutoSize = true;
			this->labelRG_fi->Location = System::Drawing::Point(12, 143);
			this->labelRG_fi->Name = L"labelRG_fi";
			this->labelRG_fi->Size = System::Drawing::Size(181, 13);
			this->labelRG_fi->TabIndex = 20;
			this->labelRG_fi->Text = L"Диаметр поршня цилиндра (fi), мм";
			// 
			// textBoxRG_P
			// 
			this->textBoxRG_P->Location = System::Drawing::Point(199, 114);
			this->textBoxRG_P->MaxLength = 16;
			this->textBoxRG_P->Name = L"textBoxRG_P";
			this->textBoxRG_P->Size = System::Drawing::Size(175, 20);
			this->textBoxRG_P->TabIndex = 17;
			this->textBoxRG_P->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelRG_P
			// 
			this->labelRG_P->AutoSize = true;
			this->labelRG_P->Location = System::Drawing::Point(12, 117);
			this->labelRG_P->Name = L"labelRG_P";
			this->labelRG_P->Size = System::Drawing::Size(98, 13);
			this->labelRG_P->TabIndex = 18;
			this->labelRG_P->Text = L"Давление (P), бар";
			// 
			// textBoxRG_n
			// 
			this->textBoxRG_n->Location = System::Drawing::Point(199, 88);
			this->textBoxRG_n->MaxLength = 16;
			this->textBoxRG_n->Name = L"textBoxRG_n";
			this->textBoxRG_n->Size = System::Drawing::Size(175, 20);
			this->textBoxRG_n->TabIndex = 16;
			this->textBoxRG_n->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelRG_n
			// 
			this->labelRG_n->AutoSize = true;
			this->labelRG_n->Location = System::Drawing::Point(12, 91);
			this->labelRG_n->Name = L"labelRG_n";
			this->labelRG_n->Size = System::Drawing::Size(135, 13);
			this->labelRG_n->TabIndex = 16;
			this->labelRG_n->Text = L"Количество цилиндров, n";
			// 
			// textBoxRG_Fst
			// 
			this->textBoxRG_Fst->Location = System::Drawing::Point(199, 62);
			this->textBoxRG_Fst->MaxLength = 16;
			this->textBoxRG_Fst->Name = L"textBoxRG_Fst";
			this->textBoxRG_Fst->Size = System::Drawing::Size(175, 20);
			this->textBoxRG_Fst->TabIndex = 15;
			this->textBoxRG_Fst->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelRG_Fst
			// 
			this->labelRG_Fst->AutoSize = true;
			this->labelRG_Fst->Location = System::Drawing::Point(12, 65);
			this->labelRG_Fst->Name = L"labelRG_Fst";
			this->labelRG_Fst->Size = System::Drawing::Size(120, 13);
			this->labelRG_Fst->TabIndex = 14;
			this->labelRG_Fst->Text = L"Общее усилие (Fst), кг";
			// 
			// labelRG
			// 
			this->labelRG->AutoSize = true;
			this->labelRG->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelRG->Location = System::Drawing::Point(11, 17);
			this->labelRG->Name = L"labelRG";
			this->labelRG->Size = System::Drawing::Size(631, 24);
			this->labelRG->TabIndex = 13;
			this->labelRG->Text = L"Расчет размеров гидроцилиндра по техническим параметрам";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->richTextBoxPN_Info);
			this->tabPage4->Controls->Add(this->groupBoxPN_res);
			this->tabPage4->Controls->Add(this->buttonPN_Enter);
			this->tabPage4->Controls->Add(this->textBoxPN_Vg);
			this->tabPage4->Controls->Add(this->labelPN_Vg);
			this->tabPage4->Controls->Add(this->textBoxPN_eta);
			this->tabPage4->Controls->Add(this->labelPN_eta);
			this->tabPage4->Controls->Add(this->textBoxPN_n);
			this->tabPage4->Controls->Add(this->labelPN_n);
			this->tabPage4->Controls->Add(this->textBoxPN_Q);
			this->tabPage4->Controls->Add(this->labelPN_Q);
			this->tabPage4->Controls->Add(this->labelPN_Header);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(784, 559);
			this->tabPage4->TabIndex = 4;
			this->tabPage4->Text = L"Расчет подачи насоса";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// richTextBoxPN_Info
			// 
			this->richTextBoxPN_Info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxPN_Info->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxPN_Info->Location = System::Drawing::Point(15, 213);
			this->richTextBoxPN_Info->Name = L"richTextBoxPN_Info";
			this->richTextBoxPN_Info->ReadOnly = true;
			this->richTextBoxPN_Info->Size = System::Drawing::Size(760, 339);
			this->richTextBoxPN_Info->TabIndex = 24;
			this->richTextBoxPN_Info->Text = resources->GetString(L"richTextBoxPN_Info.Text");
			// 
			// groupBoxPN_res
			// 
			this->groupBoxPN_res->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxPN_res->Controls->Add(this->textBoxPN_resVg);
			this->groupBoxPN_res->Controls->Add(this->labelPN_resVg);
			this->groupBoxPN_res->Controls->Add(this->textBoxPN_resQ);
			this->groupBoxPN_res->Controls->Add(this->labelPN_resQ);
			this->groupBoxPN_res->Location = System::Drawing::Point(387, 56);
			this->groupBoxPN_res->Name = L"groupBoxPN_res";
			this->groupBoxPN_res->Size = System::Drawing::Size(388, 142);
			this->groupBoxPN_res->TabIndex = 23;
			this->groupBoxPN_res->TabStop = false;
			this->groupBoxPN_res->Text = L"Результаты";
			// 
			// textBoxPN_resVg
			// 
			this->textBoxPN_resVg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxPN_resVg->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPN_resVg->Location = System::Drawing::Point(222, 32);
			this->textBoxPN_resVg->Name = L"textBoxPN_resVg";
			this->textBoxPN_resVg->ReadOnly = true;
			this->textBoxPN_resVg->Size = System::Drawing::Size(151, 20);
			this->textBoxPN_resVg->TabIndex = 13;
			this->textBoxPN_resVg->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPN_resVg
			// 
			this->labelPN_resVg->AutoSize = true;
			this->labelPN_resVg->Location = System::Drawing::Point(9, 35);
			this->labelPN_resVg->Name = L"labelPN_resVg";
			this->labelPN_resVg->Size = System::Drawing::Size(207, 13);
			this->labelPN_resVg->TabIndex = 12;
			this->labelPN_resVg->Text = L"Объем рабочей камеры насоса Vg, см³";
			// 
			// textBoxPN_resQ
			// 
			this->textBoxPN_resQ->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxPN_resQ->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxPN_resQ->Location = System::Drawing::Point(222, 58);
			this->textBoxPN_resQ->Name = L"textBoxPN_resQ";
			this->textBoxPN_resQ->ReadOnly = true;
			this->textBoxPN_resQ->Size = System::Drawing::Size(151, 20);
			this->textBoxPN_resQ->TabIndex = 15;
			this->textBoxPN_resQ->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelPN_resQ
			// 
			this->labelPN_resQ->AutoSize = true;
			this->labelPN_resQ->Location = System::Drawing::Point(9, 61);
			this->labelPN_resQ->Name = L"labelPN_resQ";
			this->labelPN_resQ->Size = System::Drawing::Size(137, 13);
			this->labelPN_resQ->TabIndex = 14;
			this->labelPN_resQ->Text = L"Подача насоса (Q), л/мин";
			// 
			// buttonPN_Enter
			// 
			this->buttonPN_Enter->Location = System::Drawing::Point(15, 166);
			this->buttonPN_Enter->Name = L"buttonPN_Enter";
			this->buttonPN_Enter->Size = System::Drawing::Size(359, 32);
			this->buttonPN_Enter->TabIndex = 22;
			this->buttonPN_Enter->Text = L"Вычилсить";
			this->buttonPN_Enter->UseVisualStyleBackColor = true;
			this->buttonPN_Enter->Click += gcnew System::EventHandler(this, &MainForm::buttonPN_Enter_Click);
			// 
			// textBoxPN_Vg
			// 
			this->textBoxPN_Vg->Location = System::Drawing::Point(225, 140);
			this->textBoxPN_Vg->MaxLength = 16;
			this->textBoxPN_Vg->Name = L"textBoxPN_Vg";
			this->textBoxPN_Vg->Size = System::Drawing::Size(149, 20);
			this->textBoxPN_Vg->TabIndex = 21;
			this->textBoxPN_Vg->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelPN_Vg
			// 
			this->labelPN_Vg->AutoSize = true;
			this->labelPN_Vg->Location = System::Drawing::Point(12, 143);
			this->labelPN_Vg->Name = L"labelPN_Vg";
			this->labelPN_Vg->Size = System::Drawing::Size(207, 13);
			this->labelPN_Vg->TabIndex = 20;
			this->labelPN_Vg->Text = L"Объем рабочей камеры насоса Vg, см³";
			// 
			// textBoxPN_eta
			// 
			this->textBoxPN_eta->Location = System::Drawing::Point(225, 114);
			this->textBoxPN_eta->MaxLength = 16;
			this->textBoxPN_eta->Name = L"textBoxPN_eta";
			this->textBoxPN_eta->Size = System::Drawing::Size(149, 20);
			this->textBoxPN_eta->TabIndex = 19;
			this->textBoxPN_eta->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelPN_eta
			// 
			this->labelPN_eta->AutoSize = true;
			this->labelPN_eta->Location = System::Drawing::Point(12, 117);
			this->labelPN_eta->Name = L"labelPN_eta";
			this->labelPN_eta->Size = System::Drawing::Size(70, 13);
			this->labelPN_eta->TabIndex = 18;
			this->labelPN_eta->Text = L"КПД насоса";
			// 
			// textBoxPN_n
			// 
			this->textBoxPN_n->Location = System::Drawing::Point(225, 88);
			this->textBoxPN_n->MaxLength = 16;
			this->textBoxPN_n->Name = L"textBoxPN_n";
			this->textBoxPN_n->Size = System::Drawing::Size(149, 20);
			this->textBoxPN_n->TabIndex = 17;
			this->textBoxPN_n->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelPN_n
			// 
			this->labelPN_n->AutoSize = true;
			this->labelPN_n->Location = System::Drawing::Point(12, 91);
			this->labelPN_n->Name = L"labelPN_n";
			this->labelPN_n->Size = System::Drawing::Size(131, 13);
			this->labelPN_n->TabIndex = 16;
			this->labelPN_n->Text = L"Обороты вала (n), 1/мин";
			// 
			// textBoxPN_Q
			// 
			this->textBoxPN_Q->Location = System::Drawing::Point(225, 62);
			this->textBoxPN_Q->MaxLength = 16;
			this->textBoxPN_Q->Name = L"textBoxPN_Q";
			this->textBoxPN_Q->Size = System::Drawing::Size(149, 20);
			this->textBoxPN_Q->TabIndex = 15;
			this->textBoxPN_Q->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelPN_Q
			// 
			this->labelPN_Q->AutoSize = true;
			this->labelPN_Q->Location = System::Drawing::Point(12, 65);
			this->labelPN_Q->Name = L"labelPN_Q";
			this->labelPN_Q->Size = System::Drawing::Size(137, 13);
			this->labelPN_Q->TabIndex = 14;
			this->labelPN_Q->Text = L"Подача насоса (Q), л/мин";
			// 
			// labelPN_Header
			// 
			this->labelPN_Header->AutoSize = true;
			this->labelPN_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPN_Header->Location = System::Drawing::Point(11, 20);
			this->labelPN_Header->Name = L"labelPN_Header";
			this->labelPN_Header->Size = System::Drawing::Size(230, 24);
			this->labelPN_Header->TabIndex = 13;
			this->labelPN_Header->Text = L"Расчет подачи насоса";
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->richTextBoxOG_Info);
			this->tabPage5->Controls->Add(this->groupBoxOG_res);
			this->tabPage5->Controls->Add(this->buttonOG_Enter);
			this->tabPage5->Controls->Add(this->labelOG_Vg);
			this->tabPage5->Controls->Add(this->textBoxOG_eta);
			this->tabPage5->Controls->Add(this->labelOG_eta);
			this->tabPage5->Controls->Add(this->textBoxOG_Vg);
			this->tabPage5->Controls->Add(this->textBoxOG_Q);
			this->tabPage5->Controls->Add(this->labelOG_Q);
			this->tabPage5->Controls->Add(this->labelOG_Header);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(784, 559);
			this->tabPage5->TabIndex = 5;
			this->tabPage5->Text = L"Расчет оборотов гидромотора";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// richTextBoxOG_Info
			// 
			this->richTextBoxOG_Info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxOG_Info->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxOG_Info->Location = System::Drawing::Point(15, 188);
			this->richTextBoxOG_Info->Name = L"richTextBoxOG_Info";
			this->richTextBoxOG_Info->ReadOnly = true;
			this->richTextBoxOG_Info->Size = System::Drawing::Size(760, 364);
			this->richTextBoxOG_Info->TabIndex = 36;
			this->richTextBoxOG_Info->Text = resources->GetString(L"richTextBoxOG_Info.Text");
			// 
			// groupBoxOG_res
			// 
			this->groupBoxOG_res->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxOG_res->Controls->Add(this->textBoxOG_resn);
			this->groupBoxOG_res->Controls->Add(this->labelOG_resn);
			this->groupBoxOG_res->Location = System::Drawing::Point(387, 56);
			this->groupBoxOG_res->Name = L"groupBoxOG_res";
			this->groupBoxOG_res->Size = System::Drawing::Size(388, 116);
			this->groupBoxOG_res->TabIndex = 35;
			this->groupBoxOG_res->TabStop = false;
			this->groupBoxOG_res->Text = L"Результаты";
			// 
			// textBoxOG_resn
			// 
			this->textBoxOG_resn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxOG_resn->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxOG_resn->Location = System::Drawing::Point(222, 32);
			this->textBoxOG_resn->Name = L"textBoxOG_resn";
			this->textBoxOG_resn->ReadOnly = true;
			this->textBoxOG_resn->Size = System::Drawing::Size(151, 20);
			this->textBoxOG_resn->TabIndex = 13;
			this->textBoxOG_resn->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelOG_resn
			// 
			this->labelOG_resn->AutoSize = true;
			this->labelOG_resn->Location = System::Drawing::Point(9, 35);
			this->labelOG_resn->Name = L"labelOG_resn";
			this->labelOG_resn->Size = System::Drawing::Size(212, 13);
			this->labelOG_resn->TabIndex = 12;
			this->labelOG_resn->Text = L"Кол-во оборотов гидромотора (n), 1/мин";
			// 
			// buttonOG_Enter
			// 
			this->buttonOG_Enter->Location = System::Drawing::Point(15, 140);
			this->buttonOG_Enter->Name = L"buttonOG_Enter";
			this->buttonOG_Enter->Size = System::Drawing::Size(359, 32);
			this->buttonOG_Enter->TabIndex = 34;
			this->buttonOG_Enter->Text = L"Вычилсить";
			this->buttonOG_Enter->UseVisualStyleBackColor = true;
			this->buttonOG_Enter->Click += gcnew System::EventHandler(this, &MainForm::buttonOG_Enter_Click);
			// 
			// labelOG_Vg
			// 
			this->labelOG_Vg->AutoSize = true;
			this->labelOG_Vg->Location = System::Drawing::Point(12, 91);
			this->labelOG_Vg->Name = L"labelOG_Vg";
			this->labelOG_Vg->Size = System::Drawing::Size(207, 13);
			this->labelOG_Vg->TabIndex = 32;
			this->labelOG_Vg->Text = L"Объем рабочей камеры насоса Vg, см³";
			// 
			// textBoxOG_eta
			// 
			this->textBoxOG_eta->Location = System::Drawing::Point(225, 114);
			this->textBoxOG_eta->MaxLength = 16;
			this->textBoxOG_eta->Name = L"textBoxOG_eta";
			this->textBoxOG_eta->Size = System::Drawing::Size(149, 20);
			this->textBoxOG_eta->TabIndex = 31;
			this->textBoxOG_eta->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelOG_eta
			// 
			this->labelOG_eta->AutoSize = true;
			this->labelOG_eta->Location = System::Drawing::Point(12, 117);
			this->labelOG_eta->Name = L"labelOG_eta";
			this->labelOG_eta->Size = System::Drawing::Size(71, 13);
			this->labelOG_eta->TabIndex = 30;
			this->labelOG_eta->Text = L"КПД мотора";
			// 
			// textBoxOG_Vg
			// 
			this->textBoxOG_Vg->Location = System::Drawing::Point(225, 88);
			this->textBoxOG_Vg->MaxLength = 16;
			this->textBoxOG_Vg->Name = L"textBoxOG_Vg";
			this->textBoxOG_Vg->Size = System::Drawing::Size(149, 20);
			this->textBoxOG_Vg->TabIndex = 29;
			this->textBoxOG_Vg->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// textBoxOG_Q
			// 
			this->textBoxOG_Q->Location = System::Drawing::Point(225, 62);
			this->textBoxOG_Q->MaxLength = 16;
			this->textBoxOG_Q->Name = L"textBoxOG_Q";
			this->textBoxOG_Q->Size = System::Drawing::Size(149, 20);
			this->textBoxOG_Q->TabIndex = 27;
			this->textBoxOG_Q->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelOG_Q
			// 
			this->labelOG_Q->AutoSize = true;
			this->labelOG_Q->Location = System::Drawing::Point(12, 65);
			this->labelOG_Q->Name = L"labelOG_Q";
			this->labelOG_Q->Size = System::Drawing::Size(137, 13);
			this->labelOG_Q->TabIndex = 26;
			this->labelOG_Q->Text = L"Подача насоса (Q), л/мин";
			// 
			// labelOG_Header
			// 
			this->labelOG_Header->AutoSize = true;
			this->labelOG_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelOG_Header->Location = System::Drawing::Point(11, 16);
			this->labelOG_Header->Name = L"labelOG_Header";
			this->labelOG_Header->Size = System::Drawing::Size(317, 24);
			this->labelOG_Header->TabIndex = 25;
			this->labelOG_Header->Text = L"Расчет оборотов гидромотора";
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->labelKMG_P);
			this->tabPage6->Controls->Add(this->richTextBoxKMG_Info);
			this->tabPage6->Controls->Add(this->groupBoxKMG_res);
			this->tabPage6->Controls->Add(this->buttonKMG_Enter);
			this->tabPage6->Controls->Add(this->textBoxKMG_eta);
			this->tabPage6->Controls->Add(this->labelKMG_eta);
			this->tabPage6->Controls->Add(this->textBoxKMG_P);
			this->tabPage6->Controls->Add(this->textBoxKMG_Vg);
			this->tabPage6->Controls->Add(this->labelKMG_Vg);
			this->tabPage6->Controls->Add(this->textBoxKMG_M);
			this->tabPage6->Controls->Add(this->labelKMG_M);
			this->tabPage6->Controls->Add(this->labelKMG_Header);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(784, 559);
			this->tabPage6->TabIndex = 6;
			this->tabPage6->Text = L"Расчет крутящего момента гидромотора (объем и давление)";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// labelKMG_P
			// 
			this->labelKMG_P->AutoSize = true;
			this->labelKMG_P->Location = System::Drawing::Point(12, 108);
			this->labelKMG_P->Name = L"labelKMG_P";
			this->labelKMG_P->Size = System::Drawing::Size(98, 13);
			this->labelKMG_P->TabIndex = 47;
			this->labelKMG_P->Text = L"Давление (P), бар";
			// 
			// richTextBoxKMG_Info
			// 
			this->richTextBoxKMG_Info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxKMG_Info->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxKMG_Info->Location = System::Drawing::Point(15, 206);
			this->richTextBoxKMG_Info->Name = L"richTextBoxKMG_Info";
			this->richTextBoxKMG_Info->ReadOnly = true;
			this->richTextBoxKMG_Info->Size = System::Drawing::Size(760, 346);
			this->richTextBoxKMG_Info->TabIndex = 41;
			this->richTextBoxKMG_Info->Text = resources->GetString(L"richTextBoxKMG_Info.Text");
			// 
			// groupBoxKMG_res
			// 
			this->groupBoxKMG_res->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxKMG_res->Controls->Add(this->radioButtonKMG_resnm);
			this->groupBoxKMG_res->Controls->Add(this->radioButtonKMG_reskgm);
			this->groupBoxKMG_res->Controls->Add(this->textBoxKMG_resVg);
			this->groupBoxKMG_res->Controls->Add(this->textBoxKMG_resM);
			this->groupBoxKMG_res->Controls->Add(this->labelKMG_resVg);
			this->groupBoxKMG_res->Controls->Add(this->labelKMG_resM);
			this->groupBoxKMG_res->Controls->Add(this->textBoxKMG_resP);
			this->groupBoxKMG_res->Controls->Add(this->labelKMG_resP);
			this->groupBoxKMG_res->Location = System::Drawing::Point(387, 47);
			this->groupBoxKMG_res->Name = L"groupBoxKMG_res";
			this->groupBoxKMG_res->Size = System::Drawing::Size(388, 142);
			this->groupBoxKMG_res->TabIndex = 40;
			this->groupBoxKMG_res->TabStop = false;
			this->groupBoxKMG_res->Text = L"Результаты";
			// 
			// radioButtonKMG_resnm
			// 
			this->radioButtonKMG_resnm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioButtonKMG_resnm->AutoSize = true;
			this->radioButtonKMG_resnm->Location = System::Drawing::Point(332, 33);
			this->radioButtonKMG_resnm->Name = L"radioButtonKMG_resnm";
			this->radioButtonKMG_resnm->Size = System::Drawing::Size(41, 17);
			this->radioButtonKMG_resnm->TabIndex = 21;
			this->radioButtonKMG_resnm->Text = L"Нм";
			this->radioButtonKMG_resnm->UseVisualStyleBackColor = true;
			// 
			// radioButtonKMG_reskgm
			// 
			this->radioButtonKMG_reskgm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioButtonKMG_reskgm->AutoSize = true;
			this->radioButtonKMG_reskgm->Checked = true;
			this->radioButtonKMG_reskgm->Location = System::Drawing::Point(284, 33);
			this->radioButtonKMG_reskgm->Name = L"radioButtonKMG_reskgm";
			this->radioButtonKMG_reskgm->Size = System::Drawing::Size(44, 17);
			this->radioButtonKMG_reskgm->TabIndex = 20;
			this->radioButtonKMG_reskgm->TabStop = true;
			this->radioButtonKMG_reskgm->Text = L"кгм";
			this->radioButtonKMG_reskgm->UseVisualStyleBackColor = true;
			this->radioButtonKMG_reskgm->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButtonKMG_reskgm_CheckedChanged);
			// 
			// textBoxKMG_resVg
			// 
			this->textBoxKMG_resVg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxKMG_resVg->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxKMG_resVg->Location = System::Drawing::Point(113, 84);
			this->textBoxKMG_resVg->Name = L"textBoxKMG_resVg";
			this->textBoxKMG_resVg->ReadOnly = true;
			this->textBoxKMG_resVg->Size = System::Drawing::Size(260, 20);
			this->textBoxKMG_resVg->TabIndex = 17;
			this->textBoxKMG_resVg->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// textBoxKMG_resM
			// 
			this->textBoxKMG_resM->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxKMG_resM->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxKMG_resM->Location = System::Drawing::Point(113, 32);
			this->textBoxKMG_resM->Name = L"textBoxKMG_resM";
			this->textBoxKMG_resM->ReadOnly = true;
			this->textBoxKMG_resM->Size = System::Drawing::Size(166, 20);
			this->textBoxKMG_resM->TabIndex = 13;
			this->textBoxKMG_resM->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelKMG_resVg
			// 
			this->labelKMG_resVg->AutoSize = true;
			this->labelKMG_resVg->Location = System::Drawing::Point(9, 87);
			this->labelKMG_resVg->Name = L"labelKMG_resVg";
			this->labelKMG_resVg->Size = System::Drawing::Size(84, 13);
			this->labelKMG_resVg->TabIndex = 16;
			this->labelKMG_resVg->Text = L"Объем(Vg), см³";
			// 
			// labelKMG_resM
			// 
			this->labelKMG_resM->AutoSize = true;
			this->labelKMG_resM->Location = System::Drawing::Point(9, 35);
			this->labelKMG_resM->Name = L"labelKMG_resM";
			this->labelKMG_resM->Size = System::Drawing::Size(65, 13);
			this->labelKMG_resM->TabIndex = 12;
			this->labelKMG_resM->Text = L"Момент (M)";
			// 
			// textBoxKMG_resP
			// 
			this->textBoxKMG_resP->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxKMG_resP->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxKMG_resP->Location = System::Drawing::Point(113, 58);
			this->textBoxKMG_resP->Name = L"textBoxKMG_resP";
			this->textBoxKMG_resP->ReadOnly = true;
			this->textBoxKMG_resP->Size = System::Drawing::Size(260, 20);
			this->textBoxKMG_resP->TabIndex = 15;
			this->textBoxKMG_resP->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelKMG_resP
			// 
			this->labelKMG_resP->AutoSize = true;
			this->labelKMG_resP->Location = System::Drawing::Point(9, 61);
			this->labelKMG_resP->Name = L"labelKMG_resP";
			this->labelKMG_resP->Size = System::Drawing::Size(98, 13);
			this->labelKMG_resP->TabIndex = 14;
			this->labelKMG_resP->Text = L"Давление (P), бар";
			// 
			// buttonKMG_Enter
			// 
			this->buttonKMG_Enter->Location = System::Drawing::Point(15, 157);
			this->buttonKMG_Enter->Name = L"buttonKMG_Enter";
			this->buttonKMG_Enter->Size = System::Drawing::Size(359, 32);
			this->buttonKMG_Enter->TabIndex = 39;
			this->buttonKMG_Enter->Text = L"Вычилсить";
			this->buttonKMG_Enter->UseVisualStyleBackColor = true;
			this->buttonKMG_Enter->Click += gcnew System::EventHandler(this, &MainForm::buttonKMG_Enter_Click);
			// 
			// textBoxKMG_eta
			// 
			this->textBoxKMG_eta->Location = System::Drawing::Point(116, 131);
			this->textBoxKMG_eta->MaxLength = 16;
			this->textBoxKMG_eta->Name = L"textBoxKMG_eta";
			this->textBoxKMG_eta->Size = System::Drawing::Size(258, 20);
			this->textBoxKMG_eta->TabIndex = 38;
			this->textBoxKMG_eta->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelKMG_eta
			// 
			this->labelKMG_eta->AutoSize = true;
			this->labelKMG_eta->Location = System::Drawing::Point(12, 134);
			this->labelKMG_eta->Name = L"labelKMG_eta";
			this->labelKMG_eta->Size = System::Drawing::Size(71, 13);
			this->labelKMG_eta->TabIndex = 37;
			this->labelKMG_eta->Text = L"КПД мотора";
			// 
			// textBoxKMG_P
			// 
			this->textBoxKMG_P->Location = System::Drawing::Point(116, 105);
			this->textBoxKMG_P->MaxLength = 16;
			this->textBoxKMG_P->Name = L"textBoxKMG_P";
			this->textBoxKMG_P->Size = System::Drawing::Size(258, 20);
			this->textBoxKMG_P->TabIndex = 36;
			this->textBoxKMG_P->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// textBoxKMG_Vg
			// 
			this->textBoxKMG_Vg->Location = System::Drawing::Point(116, 79);
			this->textBoxKMG_Vg->MaxLength = 16;
			this->textBoxKMG_Vg->Name = L"textBoxKMG_Vg";
			this->textBoxKMG_Vg->Size = System::Drawing::Size(258, 20);
			this->textBoxKMG_Vg->TabIndex = 35;
			this->textBoxKMG_Vg->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelKMG_Vg
			// 
			this->labelKMG_Vg->AutoSize = true;
			this->labelKMG_Vg->Location = System::Drawing::Point(12, 82);
			this->labelKMG_Vg->Name = L"labelKMG_Vg";
			this->labelKMG_Vg->Size = System::Drawing::Size(84, 13);
			this->labelKMG_Vg->TabIndex = 34;
			this->labelKMG_Vg->Text = L"Объем(Vg), см³";
			// 
			// textBoxKMG_M
			// 
			this->textBoxKMG_M->Location = System::Drawing::Point(116, 53);
			this->textBoxKMG_M->MaxLength = 16;
			this->textBoxKMG_M->Name = L"textBoxKMG_M";
			this->textBoxKMG_M->Size = System::Drawing::Size(258, 20);
			this->textBoxKMG_M->TabIndex = 33;
			this->textBoxKMG_M->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelKMG_M
			// 
			this->labelKMG_M->AutoSize = true;
			this->labelKMG_M->Location = System::Drawing::Point(12, 56);
			this->labelKMG_M->Name = L"labelKMG_M";
			this->labelKMG_M->Size = System::Drawing::Size(90, 13);
			this->labelKMG_M->TabIndex = 32;
			this->labelKMG_M->Text = L"Момент (M), кгм";
			// 
			// labelKMG_Header
			// 
			this->labelKMG_Header->AutoSize = true;
			this->labelKMG_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelKMG_Header->Location = System::Drawing::Point(11, 3);
			this->labelKMG_Header->Name = L"labelKMG_Header";
			this->labelKMG_Header->Size = System::Drawing::Size(617, 24);
			this->labelKMG_Header->TabIndex = 31;
			this->labelKMG_Header->Text = L"Расчет крутящего момента гидромотора (объем и давление)";
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->richTextBoxKMV_Info);
			this->tabPage7->Controls->Add(this->groupBoxKMV_res);
			this->tabPage7->Controls->Add(this->buttonKMV_Enter);
			this->tabPage7->Controls->Add(this->textBoxKMV_nn);
			this->tabPage7->Controls->Add(this->labelKMV_nn);
			this->tabPage7->Controls->Add(this->textBoxKMV_N);
			this->tabPage7->Controls->Add(this->labelKMV_N);
			this->tabPage7->Controls->Add(this->labelKMV_Header);
			this->tabPage7->Location = System::Drawing::Point(4, 22);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(784, 559);
			this->tabPage7->TabIndex = 7;
			this->tabPage7->Text = L"Расчет крутящего момента на валу (мощность и обороты)";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// richTextBoxKMV_Info
			// 
			this->richTextBoxKMV_Info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxKMV_Info->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxKMV_Info->Location = System::Drawing::Point(15, 155);
			this->richTextBoxKMV_Info->Name = L"richTextBoxKMV_Info";
			this->richTextBoxKMV_Info->ReadOnly = true;
			this->richTextBoxKMV_Info->Size = System::Drawing::Size(760, 398);
			this->richTextBoxKMV_Info->TabIndex = 58;
			this->richTextBoxKMV_Info->Text = resources->GetString(L"richTextBoxKMV_Info.Text");
			// 
			// groupBoxKMV_res
			// 
			this->groupBoxKMV_res->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxKMV_res->Controls->Add(this->radioButtonKMV_resMhm);
			this->groupBoxKMV_res->Controls->Add(this->radioButtonKMV_resMkgm);
			this->groupBoxKMV_res->Controls->Add(this->textBoxKMV_resM);
			this->groupBoxKMV_res->Controls->Add(this->label6KMV_resM);
			this->groupBoxKMV_res->Location = System::Drawing::Point(387, 47);
			this->groupBoxKMV_res->Name = L"groupBoxKMV_res";
			this->groupBoxKMV_res->Size = System::Drawing::Size(388, 90);
			this->groupBoxKMV_res->TabIndex = 57;
			this->groupBoxKMV_res->TabStop = false;
			this->groupBoxKMV_res->Text = L"Результаты";
			// 
			// radioButtonKMV_resMhm
			// 
			this->radioButtonKMV_resMhm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioButtonKMV_resMhm->AutoSize = true;
			this->radioButtonKMV_resMhm->Location = System::Drawing::Point(332, 33);
			this->radioButtonKMV_resMhm->Name = L"radioButtonKMV_resMhm";
			this->radioButtonKMV_resMhm->Size = System::Drawing::Size(41, 17);
			this->radioButtonKMV_resMhm->TabIndex = 21;
			this->radioButtonKMV_resMhm->Text = L"Нм";
			this->radioButtonKMV_resMhm->UseVisualStyleBackColor = true;
			// 
			// radioButtonKMV_resMkgm
			// 
			this->radioButtonKMV_resMkgm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioButtonKMV_resMkgm->AutoSize = true;
			this->radioButtonKMV_resMkgm->Checked = true;
			this->radioButtonKMV_resMkgm->Location = System::Drawing::Point(284, 33);
			this->radioButtonKMV_resMkgm->Name = L"radioButtonKMV_resMkgm";
			this->radioButtonKMV_resMkgm->Size = System::Drawing::Size(44, 17);
			this->radioButtonKMV_resMkgm->TabIndex = 20;
			this->radioButtonKMV_resMkgm->TabStop = true;
			this->radioButtonKMV_resMkgm->Text = L"кгм";
			this->radioButtonKMV_resMkgm->UseVisualStyleBackColor = true;
			this->radioButtonKMV_resMkgm->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButtonKMV_resMkgm_CheckedChanged);
			// 
			// textBoxKMV_resM
			// 
			this->textBoxKMV_resM->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxKMV_resM->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxKMV_resM->Location = System::Drawing::Point(113, 32);
			this->textBoxKMV_resM->Name = L"textBoxKMV_resM";
			this->textBoxKMV_resM->ReadOnly = true;
			this->textBoxKMV_resM->Size = System::Drawing::Size(166, 20);
			this->textBoxKMV_resM->TabIndex = 13;
			this->textBoxKMV_resM->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// label6KMV_resM
			// 
			this->label6KMV_resM->AutoSize = true;
			this->label6KMV_resM->Location = System::Drawing::Point(9, 35);
			this->label6KMV_resM->Name = L"label6KMV_resM";
			this->label6KMV_resM->Size = System::Drawing::Size(65, 13);
			this->label6KMV_resM->TabIndex = 12;
			this->label6KMV_resM->Text = L"Момент (M)";
			// 
			// buttonKMV_Enter
			// 
			this->buttonKMV_Enter->Location = System::Drawing::Point(15, 105);
			this->buttonKMV_Enter->Name = L"buttonKMV_Enter";
			this->buttonKMV_Enter->Size = System::Drawing::Size(359, 32);
			this->buttonKMV_Enter->TabIndex = 56;
			this->buttonKMV_Enter->Text = L"Вычилсить";
			this->buttonKMV_Enter->UseVisualStyleBackColor = true;
			this->buttonKMV_Enter->Click += gcnew System::EventHandler(this, &MainForm::buttonKMV_Enter_Click);
			// 
			// textBoxKMV_nn
			// 
			this->textBoxKMV_nn->Location = System::Drawing::Point(200, 79);
			this->textBoxKMV_nn->MaxLength = 16;
			this->textBoxKMV_nn->Name = L"textBoxKMV_nn";
			this->textBoxKMV_nn->Size = System::Drawing::Size(174, 20);
			this->textBoxKMV_nn->TabIndex = 52;
			this->textBoxKMV_nn->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelKMV_nn
			// 
			this->labelKMV_nn->AutoSize = true;
			this->labelKMV_nn->Location = System::Drawing::Point(12, 82);
			this->labelKMV_nn->Name = L"labelKMV_nn";
			this->labelKMV_nn->Size = System::Drawing::Size(182, 13);
			this->labelKMV_nn->TabIndex = 51;
			this->labelKMV_nn->Text = L"Частота вращения вала (n), 1/мин";
			// 
			// textBoxKMV_N
			// 
			this->textBoxKMV_N->Location = System::Drawing::Point(200, 53);
			this->textBoxKMV_N->MaxLength = 16;
			this->textBoxKMV_N->Name = L"textBoxKMV_N";
			this->textBoxKMV_N->Size = System::Drawing::Size(174, 20);
			this->textBoxKMV_N->TabIndex = 50;
			this->textBoxKMV_N->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelKMV_N
			// 
			this->labelKMV_N->AutoSize = true;
			this->labelKMV_N->Location = System::Drawing::Point(12, 56);
			this->labelKMV_N->Name = L"labelKMV_N";
			this->labelKMV_N->Size = System::Drawing::Size(101, 13);
			this->labelKMV_N->TabIndex = 49;
			this->labelKMV_N->Text = L"Мощность (N), кВт";
			// 
			// labelKMV_Header
			// 
			this->labelKMV_Header->AutoSize = true;
			this->labelKMV_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelKMV_Header->Location = System::Drawing::Point(11, 3);
			this->labelKMV_Header->Name = L"labelKMV_Header";
			this->labelKMV_Header->Size = System::Drawing::Size(585, 24);
			this->labelKMV_Header->TabIndex = 48;
			this->labelKMV_Header->Text = L"Расчет крутящего момента на валу (мощность и обороты)";
			// 
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->pictureBoxOPN_Img);
			this->tabPage8->Controls->Add(this->labelOPN_L);
			this->tabPage8->Controls->Add(this->richTextBoxOPN_Info);
			this->tabPage8->Controls->Add(this->groupBoxOPN_res);
			this->tabPage8->Controls->Add(this->buttonOPN_Enter);
			this->tabPage8->Controls->Add(this->textBoxOPN_L);
			this->tabPage8->Controls->Add(this->textBoxOPN_D);
			this->tabPage8->Controls->Add(this->labelOPN_D);
			this->tabPage8->Controls->Add(this->textBoxOPN_W);
			this->tabPage8->Controls->Add(this->labelOPN_W);
			this->tabPage8->Controls->Add(this->labelOPN_Header);
			this->tabPage8->Location = System::Drawing::Point(4, 22);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(784, 559);
			this->tabPage8->TabIndex = 8;
			this->tabPage8->Text = L"Расчёт объёма пластинчатого насоса по геометрическим размерам";
			this->tabPage8->UseVisualStyleBackColor = true;
			// 
			// pictureBoxOPN_Img
			// 
			this->pictureBoxOPN_Img->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->pictureBoxOPN_Img->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBoxOPN_Img->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBoxOPN_Img->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxOPN_Img.Image")));
			this->pictureBoxOPN_Img->Location = System::Drawing::Point(15, 178);
			this->pictureBoxOPN_Img->Name = L"pictureBoxOPN_Img";
			this->pictureBoxOPN_Img->Size = System::Drawing::Size(359, 374);
			this->pictureBoxOPN_Img->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxOPN_Img->TabIndex = 60;
			this->pictureBoxOPN_Img->TabStop = false;
			// 
			// labelOPN_L
			// 
			this->labelOPN_L->AutoSize = true;
			this->labelOPN_L->Location = System::Drawing::Point(12, 108);
			this->labelOPN_L->Name = L"labelOPN_L";
			this->labelOPN_L->Size = System::Drawing::Size(55, 13);
			this->labelOPN_L->TabIndex = 59;
			this->labelOPN_L->Text = L"Длина (L)";
			// 
			// richTextBoxOPN_Info
			// 
			this->richTextBoxOPN_Info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxOPN_Info->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxOPN_Info->Location = System::Drawing::Point(387, 178);
			this->richTextBoxOPN_Info->Name = L"richTextBoxOPN_Info";
			this->richTextBoxOPN_Info->ReadOnly = true;
			this->richTextBoxOPN_Info->Size = System::Drawing::Size(388, 374);
			this->richTextBoxOPN_Info->TabIndex = 58;
			this->richTextBoxOPN_Info->Text = resources->GetString(L"richTextBoxOPN_Info.Text");
			// 
			// groupBoxOPN_res
			// 
			this->groupBoxOPN_res->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxOPN_res->Controls->Add(this->textBoxOPN_resV);
			this->groupBoxOPN_res->Controls->Add(this->labelOPN_resV);
			this->groupBoxOPN_res->Location = System::Drawing::Point(387, 47);
			this->groupBoxOPN_res->Name = L"groupBoxOPN_res";
			this->groupBoxOPN_res->Size = System::Drawing::Size(388, 116);
			this->groupBoxOPN_res->TabIndex = 57;
			this->groupBoxOPN_res->TabStop = false;
			this->groupBoxOPN_res->Text = L"Результаты";
			// 
			// textBoxOPN_resV
			// 
			this->textBoxOPN_resV->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxOPN_resV->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxOPN_resV->Location = System::Drawing::Point(57, 32);
			this->textBoxOPN_resV->Name = L"textBoxOPN_resV";
			this->textBoxOPN_resV->ReadOnly = true;
			this->textBoxOPN_resV->Size = System::Drawing::Size(316, 20);
			this->textBoxOPN_resV->TabIndex = 13;
			this->textBoxOPN_resV->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelOPN_resV
			// 
			this->labelOPN_resV->AutoSize = true;
			this->labelOPN_resV->Location = System::Drawing::Point(9, 35);
			this->labelOPN_resV->Name = L"labelOPN_resV";
			this->labelOPN_resV->Size = System::Drawing::Size(42, 13);
			this->labelOPN_resV->TabIndex = 12;
			this->labelOPN_resV->Text = L"Объем";
			// 
			// buttonOPN_Enter
			// 
			this->buttonOPN_Enter->Location = System::Drawing::Point(15, 131);
			this->buttonOPN_Enter->Name = L"buttonOPN_Enter";
			this->buttonOPN_Enter->Size = System::Drawing::Size(359, 32);
			this->buttonOPN_Enter->TabIndex = 56;
			this->buttonOPN_Enter->Text = L"Вычилсить";
			this->buttonOPN_Enter->UseVisualStyleBackColor = true;
			this->buttonOPN_Enter->Click += gcnew System::EventHandler(this, &MainForm::buttonOPN_Enter_Click);
			// 
			// textBoxOPN_L
			// 
			this->textBoxOPN_L->Location = System::Drawing::Point(88, 105);
			this->textBoxOPN_L->MaxLength = 16;
			this->textBoxOPN_L->Name = L"textBoxOPN_L";
			this->textBoxOPN_L->Size = System::Drawing::Size(286, 20);
			this->textBoxOPN_L->TabIndex = 53;
			this->textBoxOPN_L->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// textBoxOPN_D
			// 
			this->textBoxOPN_D->Location = System::Drawing::Point(88, 79);
			this->textBoxOPN_D->MaxLength = 16;
			this->textBoxOPN_D->Name = L"textBoxOPN_D";
			this->textBoxOPN_D->Size = System::Drawing::Size(286, 20);
			this->textBoxOPN_D->TabIndex = 52;
			this->textBoxOPN_D->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelOPN_D
			// 
			this->labelOPN_D->AutoSize = true;
			this->labelOPN_D->Location = System::Drawing::Point(12, 82);
			this->labelOPN_D->Name = L"labelOPN_D";
			this->labelOPN_D->Size = System::Drawing::Size(70, 13);
			this->labelOPN_D->TabIndex = 51;
			this->labelOPN_D->Text = L"Диаметр (D)";
			// 
			// textBoxOPN_W
			// 
			this->textBoxOPN_W->Location = System::Drawing::Point(88, 53);
			this->textBoxOPN_W->MaxLength = 16;
			this->textBoxOPN_W->Name = L"textBoxOPN_W";
			this->textBoxOPN_W->Size = System::Drawing::Size(286, 20);
			this->textBoxOPN_W->TabIndex = 50;
			this->textBoxOPN_W->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelOPN_W
			// 
			this->labelOPN_W->AutoSize = true;
			this->labelOPN_W->Location = System::Drawing::Point(12, 56);
			this->labelOPN_W->Name = L"labelOPN_W";
			this->labelOPN_W->Size = System::Drawing::Size(66, 13);
			this->labelOPN_W->TabIndex = 49;
			this->labelOPN_W->Text = L"Ширина (W)";
			// 
			// labelOPN_Header
			// 
			this->labelOPN_Header->AutoSize = true;
			this->labelOPN_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelOPN_Header->Location = System::Drawing::Point(11, 3);
			this->labelOPN_Header->Name = L"labelOPN_Header";
			this->labelOPN_Header->Size = System::Drawing::Size(689, 24);
			this->labelOPN_Header->TabIndex = 48;
			this->labelOPN_Header->Text = L"Расчёт объёма пластинчатого насоса по геометрическим размерам";
			// 
			// tabPage9
			// 
			this->tabPage9->Controls->Add(this->pictureBoxOShN_Img);
			this->tabPage9->Controls->Add(this->labelOShN_L);
			this->tabPage9->Controls->Add(this->richTextBoxOShN_Info);
			this->tabPage9->Controls->Add(this->groupBoxOShN_res);
			this->tabPage9->Controls->Add(this->buttonOShN_Enter);
			this->tabPage9->Controls->Add(this->textBoxOShN_L);
			this->tabPage9->Controls->Add(this->textBoxOShN_D);
			this->tabPage9->Controls->Add(this->labelOShN_D);
			this->tabPage9->Controls->Add(this->textBoxOShN_W);
			this->tabPage9->Controls->Add(this->labelOShN_W);
			this->tabPage9->Controls->Add(this->labelOShN_Header);
			this->tabPage9->Location = System::Drawing::Point(4, 22);
			this->tabPage9->Name = L"tabPage9";
			this->tabPage9->Padding = System::Windows::Forms::Padding(3);
			this->tabPage9->Size = System::Drawing::Size(784, 559);
			this->tabPage9->TabIndex = 9;
			this->tabPage9->Text = L"Расчёт объёма шестеренного насоса по геометрическим размерам";
			this->tabPage9->UseVisualStyleBackColor = true;
			// 
			// pictureBoxOShN_Img
			// 
			this->pictureBoxOShN_Img->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->pictureBoxOShN_Img->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBoxOShN_Img->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBoxOShN_Img->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxOShN_Img.Image")));
			this->pictureBoxOShN_Img->Location = System::Drawing::Point(16, 178);
			this->pictureBoxOShN_Img->Name = L"pictureBoxOShN_Img";
			this->pictureBoxOShN_Img->Size = System::Drawing::Size(359, 374);
			this->pictureBoxOShN_Img->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxOShN_Img->TabIndex = 71;
			this->pictureBoxOShN_Img->TabStop = false;
			// 
			// labelOShN_L
			// 
			this->labelOShN_L->AutoSize = true;
			this->labelOShN_L->Location = System::Drawing::Point(13, 108);
			this->labelOShN_L->Name = L"labelOShN_L";
			this->labelOShN_L->Size = System::Drawing::Size(55, 13);
			this->labelOShN_L->TabIndex = 70;
			this->labelOShN_L->Text = L"Длина (L)";
			// 
			// richTextBoxOShN_Info
			// 
			this->richTextBoxOShN_Info->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBoxOShN_Info->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBoxOShN_Info->Location = System::Drawing::Point(388, 178);
			this->richTextBoxOShN_Info->Name = L"richTextBoxOShN_Info";
			this->richTextBoxOShN_Info->ReadOnly = true;
			this->richTextBoxOShN_Info->Size = System::Drawing::Size(388, 374);
			this->richTextBoxOShN_Info->TabIndex = 69;
			this->richTextBoxOShN_Info->Text = L"Для этого необходимо замерить 3 размера в сантиметрах, в результате вычисления по"
				L"лучается подача насоса с см³ за один оборот.\nМожно измерять в других единицах.";
			// 
			// groupBoxOShN_res
			// 
			this->groupBoxOShN_res->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxOShN_res->Controls->Add(this->textBoxOShN_resV);
			this->groupBoxOShN_res->Controls->Add(this->labelOShN_resV);
			this->groupBoxOShN_res->Location = System::Drawing::Point(388, 47);
			this->groupBoxOShN_res->Name = L"groupBoxOShN_res";
			this->groupBoxOShN_res->Size = System::Drawing::Size(388, 116);
			this->groupBoxOShN_res->TabIndex = 68;
			this->groupBoxOShN_res->TabStop = false;
			this->groupBoxOShN_res->Text = L"Результаты";
			// 
			// textBoxOShN_resV
			// 
			this->textBoxOShN_resV->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxOShN_resV->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBoxOShN_resV->Location = System::Drawing::Point(57, 32);
			this->textBoxOShN_resV->Name = L"textBoxOShN_resV";
			this->textBoxOShN_resV->ReadOnly = true;
			this->textBoxOShN_resV->Size = System::Drawing::Size(316, 20);
			this->textBoxOShN_resV->TabIndex = 13;
			this->textBoxOShN_resV->Click += gcnew System::EventHandler(this, &MainForm::copy_Click);
			// 
			// labelOShN_resV
			// 
			this->labelOShN_resV->AutoSize = true;
			this->labelOShN_resV->Location = System::Drawing::Point(9, 35);
			this->labelOShN_resV->Name = L"labelOShN_resV";
			this->labelOShN_resV->Size = System::Drawing::Size(42, 13);
			this->labelOShN_resV->TabIndex = 12;
			this->labelOShN_resV->Text = L"Объем";
			// 
			// buttonOShN_Enter
			// 
			this->buttonOShN_Enter->Location = System::Drawing::Point(16, 131);
			this->buttonOShN_Enter->Name = L"buttonOShN_Enter";
			this->buttonOShN_Enter->Size = System::Drawing::Size(359, 32);
			this->buttonOShN_Enter->TabIndex = 67;
			this->buttonOShN_Enter->Text = L"Вычилсить";
			this->buttonOShN_Enter->UseVisualStyleBackColor = true;
			this->buttonOShN_Enter->Click += gcnew System::EventHandler(this, &MainForm::buttonOShN_Enter_Click);
			// 
			// textBoxOShN_L
			// 
			this->textBoxOShN_L->Location = System::Drawing::Point(89, 105);
			this->textBoxOShN_L->MaxLength = 16;
			this->textBoxOShN_L->Name = L"textBoxOShN_L";
			this->textBoxOShN_L->Size = System::Drawing::Size(286, 20);
			this->textBoxOShN_L->TabIndex = 66;
			this->textBoxOShN_L->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// textBoxOShN_D
			// 
			this->textBoxOShN_D->Location = System::Drawing::Point(89, 79);
			this->textBoxOShN_D->MaxLength = 16;
			this->textBoxOShN_D->Name = L"textBoxOShN_D";
			this->textBoxOShN_D->Size = System::Drawing::Size(286, 20);
			this->textBoxOShN_D->TabIndex = 65;
			this->textBoxOShN_D->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelOShN_D
			// 
			this->labelOShN_D->AutoSize = true;
			this->labelOShN_D->Location = System::Drawing::Point(13, 82);
			this->labelOShN_D->Name = L"labelOShN_D";
			this->labelOShN_D->Size = System::Drawing::Size(70, 13);
			this->labelOShN_D->TabIndex = 64;
			this->labelOShN_D->Text = L"Диаметр (D)";
			// 
			// textBoxOShN_W
			// 
			this->textBoxOShN_W->Location = System::Drawing::Point(89, 53);
			this->textBoxOShN_W->MaxLength = 16;
			this->textBoxOShN_W->Name = L"textBoxOShN_W";
			this->textBoxOShN_W->Size = System::Drawing::Size(286, 20);
			this->textBoxOShN_W->TabIndex = 63;
			this->textBoxOShN_W->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::Float_KeyPress);
			// 
			// labelOShN_W
			// 
			this->labelOShN_W->AutoSize = true;
			this->labelOShN_W->Location = System::Drawing::Point(13, 56);
			this->labelOShN_W->Name = L"labelOShN_W";
			this->labelOShN_W->Size = System::Drawing::Size(66, 13);
			this->labelOShN_W->TabIndex = 62;
			this->labelOShN_W->Text = L"Ширина (W)";
			// 
			// labelOShN_Header
			// 
			this->labelOShN_Header->AutoSize = true;
			this->labelOShN_Header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelOShN_Header->Location = System::Drawing::Point(12, 3);
			this->labelOShN_Header->Name = L"labelOShN_Header";
			this->labelOShN_Header->Size = System::Drawing::Size(685, 24);
			this->labelOShN_Header->TabIndex = 61;
			this->labelOShN_Header->Text = L"Расчёт объёма шестеренного насоса по геометрическим размерам";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 613);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(800, 640);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Hydculator – расчет гидравлики";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBoxGP_Results->ResumeLayout(false);
			this->groupBoxGP_Results->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBoxDT_res->ResumeLayout(false);
			this->groupBoxDT_res->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->groupBoxPG_res->ResumeLayout(false);
			this->groupBoxPG_res->PerformLayout();
			this->tabPageRG->ResumeLayout(false);
			this->tabPageRG->PerformLayout();
			this->groupBoxRG_res->ResumeLayout(false);
			this->groupBoxRG_res->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->groupBoxPN_res->ResumeLayout(false);
			this->groupBoxPN_res->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->groupBoxOG_res->ResumeLayout(false);
			this->groupBoxOG_res->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->groupBoxKMG_res->ResumeLayout(false);
			this->groupBoxKMG_res->PerformLayout();
			this->tabPage7->ResumeLayout(false);
			this->tabPage7->PerformLayout();
			this->groupBoxKMV_res->ResumeLayout(false);
			this->groupBoxKMV_res->PerformLayout();
			this->tabPage8->ResumeLayout(false);
			this->tabPage8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOPN_Img))->EndInit();
			this->groupBoxOPN_res->ResumeLayout(false);
			this->groupBoxOPN_res->PerformLayout();
			this->tabPage9->ResumeLayout(false);
			this->tabPage9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOShN_Img))->EndInit();
			this->groupBoxOShN_res->ResumeLayout(false);
			this->groupBoxOShN_res->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

	private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		AboutForm^ af = gcnew AboutForm();
		af->ShowDialog();
	}

	// расчет мощности, расхода и давления гидропривода
	private: System::Void buttonGP_Enter_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear results
		textBoxGP_resN->Text ="";
		textBoxGP_resP->Text ="";
		textBoxGP_resQ->Text ="";

		// vars init
		double N, P, Q, eta, resN, resP, resQ;
		N = getText(textBoxGP_N);
		P = getText(textBoxGP_P);
		Q = getText(textBoxGP_Q);
		eta = getText(textBoxGP_eta);

		// расчет мощности
		if (Q > 0 && P > 0 && eta > 0) {
			double k = 1;
			if (radioButtonGP_N2->Checked) {
				k = HF2kWt;
			}
			resN = Math::Round((Q * P) / (612 * eta) / k, COUNT_DECIMAL);
			textBoxGP_resN->Text = Convert::ToString(resN, nfi);
		}

		// расчет давления
		if (N > 0 && Q > 0 && eta > 0) {
			resP = Math::Round(N * 612 * eta / Q, COUNT_DECIMAL);
			textBoxGP_resP->Text = Convert::ToString(resP, nfi);
		}

		// расчет подачи насоса
		if (N > 0 && P > 0 && eta > 0) {
			resQ = Math::Round(N * 612 * eta / P, COUNT_DECIMAL);
			textBoxGP_resQ->Text = Convert::ToString(resQ, nfi);
		}

	}

	private: System::Void Float_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		int number = e->KeyChar;

		// цифры, backspace, точка и ctrl+v
		if (!Char::IsDigit(number) && number != 8 && number != 46 && number != 22) {
			e->Handled = true;
		}
	}

	private: double getText(Windows::Forms::TextBox^ textBox) {
		double result = 0;
		if (textBox->Text !="") {
			if (!Double::TryParse(textBox->Text, Globalization::NumberStyles::Float, nfi, result)) {
				textBox->Focus();
				MessageBox::Show(L"Поле имеет недопустимое значение", L"Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			};
		};
		return result;
	}

	private: System::Void radioButtonGP_N1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBoxGP_resN->Text !="0" || textBoxGP_resN->Text !="") {
			double N = getText(textBoxGP_resN);
			double k = 1;

			if (radioButtonGP_N2->Checked) {
				k = HF2kWt;
			} else {
				k = 1 / HF2kWt;
			}

			if (N > 0) {
				N = Math::Round(N / k, COUNT_DECIMAL);
				textBoxGP_resN->Text = Convert::ToString(N, nfi);
			}
		}
	}

	private: System::Void copy_Click(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ clickedTextBox = safe_cast<TextBox^>(sender);
		if (clickedTextBox->Text !="") {
			ToolTip^ t = gcnew ToolTip();
			Clipboard::SetText(clickedTextBox->Text);
			t->SetToolTip(clickedTextBox, L"Скопировано");
		}
	}
	
	// Расчет диаметра трубопровода, скорости потока
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear results
		textBoxDT_resD->Text ="";
		textBoxDT_resV->Text ="";
		textBoxDT_resQ->Text ="";

		// vars init
		double D, V, Q, resD, resV, resQ;
		D = getText(textBoxDT_D);
		V = getText(textBoxDT_V);
		Q = getText(textBoxDT_Q);

		// расчет подачи насоса
		if (V > 0 && D > 0) {
			resQ = Math::Round((D * D * V) / 21.2, COUNT_DECIMAL);
			textBoxDT_resQ->Text = Convert::ToString(resQ, nfi);
		}

		// расчет диаметра
		if (V > 0 && Q > 0) {
			resD = Math::Round(Math::Sqrt((Q * 21.2) / V), COUNT_DECIMAL);
			textBoxDT_resD->Text = Convert::ToString(resD, nfi);
		}

		// расчет скорости потока
		if (D > 0 && Q > 0) {
			resV = Math::Round((Q * 21.2) / (D * D), COUNT_DECIMAL);
			textBoxDT_resV->Text = Convert::ToString(resV, nfi);
		}
	}

	// расчет параметров гидроцилиндра по его размерам
	private: System::Void buttonPG_Enter_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear results
		textBoxPG_SP->Text ="";
		textBoxPG_SSh->Text ="";
		textBoxPG_SK->Text ="";
		textBoxPG_VPP->Text ="";
		textBoxPG_CVPP->Text ="";
		textBoxPG_VShP->Text ="";
		textBoxPG_CVShP->Text ="";
		textBoxPG_QVSh->Text ="";
		textBoxPG_QPP->Text ="";
		textBoxPG_DQPShP->Text ="";
		textBoxPG_NVtSh->Text ="";
		textBoxPG_NVC->Text ="";
		textBoxPG_FShC->Text ="";
		textBoxPG_SumFVt->Text ="";
		textBoxPG_FVtSh->Text ="";
		textBoxPG_SumFV->Text ="";

		// vars init
		double n, DP, DSh, LSh, P, V, res;
		n = getText(textBoxPG_n);
		DP = getText(textBoxPG_DP);
		DSh = getText(textBoxBG_DSh);
		LSh = getText(textBoxPG_LSh);
		P = getText(textBoxPG_P);
		V = getText(textBoxPG_V);

		// расчет площади поршня
		if (DP > 0) {
			res = Math::Round(SRound(DP), COUNT_DECIMAL);
			textBoxPG_SP->Text = Convert::ToString(res, nfi);
		}

		// расчет площади штока
		if (DSh > 0) {
			res = Math::Round(SRound(DSh), COUNT_DECIMAL);
			textBoxPG_SSh->Text = Convert::ToString(res, nfi);
		}

		// расчет площади кольца
		if (DP > 0 && DSh > 0 && DP > DSh) {
			res = Math::Round(SRound(DP) - SRound(DSh), COUNT_DECIMAL);
			textBoxPG_SK->Text = Convert::ToString(res, nfi);
		}

		// расчет объема поршневой полости
		if (DP > 0 && LSh > 0) {
			res = Math::Round(SRound(DP) * LSh / 10 / 1000, COUNT_DECIMAL);
			textBoxPG_VPP->Text = Convert::ToString(res, nfi);
		}

		// расчет общего объема поршневой полости
		if (DP > 0 && LSh > 0 && n > 0) {
			res = Math::Round(SRound(DP) * LSh / 10 / 1000 * n, COUNT_DECIMAL);
			textBoxPG_CVPP->Text = Convert::ToString(res, nfi);
		}

		// расчет объем штоковой полости
		if (DP > 0 && DSh > 0 && LSh > 0) {
			res = Math::Round((SRound(DP) - SRound(DSh)) * LSh / 10 / 1000, COUNT_DECIMAL);
			textBoxPG_VShP->Text = Convert::ToString(res, nfi);
		}

		// расчет общего объема штоковой полости
		if (DP > 0 && DSh > 0 && LSh > 0 && n > 0) {
			res = Math::Round((SRound(DP) - SRound(DSh)) * LSh / 10 / 1000 * n, COUNT_DECIMAL);
			textBoxPG_CVShP->Text = Convert::ToString(res, nfi);
		}

		// расчет расхода при втягивании штока
		if (DP > 0 && V > 0) {
			res = Math::Round(SRound(DP) * V / 10, COUNT_DECIMAL);
			textBoxPG_QVSh->Text = Convert::ToString(res, nfi);
		}

		// расчет расхода в поршневой полости
		if (DP > 0 && DSh > 0 && V > 0) {
			res = Math::Round((SRound(DP) - SRound(DSh)) * V / 10, COUNT_DECIMAL);
			textBoxPG_QPP->Text = Convert::ToString(res, nfi);
		}

		// расчет разницы расхода поршневой и штоковой полостей
		if (DP > 0 && DSh > 0 && V > 0) {
			res = Math::Round(SRound(DP) / (SRound(DP) - SRound(DSh)) * SRound(DP) * V / 10, COUNT_DECIMAL);
			textBoxPG_DQPShP->Text = Convert::ToString(res, nfi);
		}

		// расчет мощности втягивания штока
		if (DP > 0 && P > 0 && V > 0) {
			res = Math::Round(SRound(DP) * V / 10 * P / 400 * HF2kWt, COUNT_DECIMAL);
			textBoxPG_NVtSh->Text = Convert::ToString(res, nfi);
		}

		// расчет мощности выталкивания штока цилиндра
		if (DP > 0 && DSh > 0 && P > 0 && V > 0) {
			res = Math::Round((SRound(DP) - SRound(DSh)) * V / 10 * P / 400 * HF2kWt, COUNT_DECIMAL);
			textBoxPG_NVC->Text = Convert::ToString(res, nfi);
		}

		// расчет усилия выталкивания штока цилиндра
		if (DP > 0 && P > 0) {
			res = Math::Round(SRound(DP) * P, COUNT_DECIMAL);
			textBoxPG_FShC->Text = Convert::ToString(res, nfi);
		}

		// расчет суммарного усилия выталкивания
		if (DP > 0 && P > 0 && n > 0) {
			res = Math::Round(SRound(DP) * P * n, COUNT_DECIMAL);
			textBoxPG_SumFVt->Text = Convert::ToString(res, nfi);
		}

		// расчет усилия втягивания
		if (DP > 0 && DSh > 0 && P > 0) {
			res = Math::Round((SRound(DP) - SRound(DSh)) * P, COUNT_DECIMAL);
			textBoxPG_FVtSh->Text = Convert::ToString(res, nfi);
		}

		// расчет суммарного усилия втягивания
		if (DP > 0 && DSh > 0 && P > 0 && n > 0) {
			res = Math::Round((SRound(DP) - SRound(DSh)) * P * n, COUNT_DECIMAL);
			textBoxPG_SumFV->Text = Convert::ToString(res, nfi);
		}
	}

	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		// сохранение значений
		WritePrivateProfileString(NULL, NULL, NULL, L".\\hydculator.ini");
		SetIniValue("COUNT_DECIMAL", Convert::ToString(COUNT_DECIMAL));

		for each (Control ^ tab in tabControl1->Controls)
		{
			for each (Control ^ c in tab->Controls)
			{
				if (c->GetType()->ToString() == L"System.Windows.Forms.TextBox") {
					SetIniValue(c->Name, c->Text);
				}
			}
		}
		// tabControl selected index
		int index = tabControl1->SelectedIndex;
		SetIniValue("TabIndex", Convert::ToString(index));
	}

	// расчет размеров гидроцилиндра по техническим параметрам
	private: System::Void buttonRG_Enter_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear results
		textBoxRG_resSp->Text ="";
		textBoxRG_resP->Text ="";
		textBoxRG_resfi->Text ="";
		textBoxRG_resv->Text ="";

		// vars init
		double Fst, n, P, fi, L, t, Sp, res;
		Fst = getText(textBoxRG_Fst);
		n = getText(textBoxRG_n);
		P = getText(textBoxRG_P);
		fi = getText(textBoxRG_fi);
		L = getText(textBoxRG_L);
		t = getText(textBoxRG_t);
		Sp = getText(textBoxRG_Sp);

		// расчет площади поршня
		if (Fst > 0 && P > 0 && n > 0) {
			res = Math::Round(Fst / (P * n), COUNT_DECIMAL);
			textBoxRG_resSp->Text = Convert::ToString(res, nfi);
		}

		// расчет давления
		if (Fst > 0 && Sp > 0 && n > 0) {
			res = Math::Round(Fst / (n * Sp), COUNT_DECIMAL);
			textBoxRG_resP->Text = Convert::ToString(res, nfi);
		}

		// расчет диаметра поршня цилиндра
		if (Fst > 0 && P > 0 && n > 0) {
			res = Math::Round(Math::Sqrt(Fst / (P * n) * 400 / Math::PI), COUNT_DECIMAL);
			textBoxRG_resfi->Text = Convert::ToString(res, nfi);
		}

		// расчет скорости выдвижения штока
		if (L > 0 && t > 0) {
			res = Math::Round(L / t * 0.06, COUNT_DECIMAL);
			textBoxRG_resv->Text = Convert::ToString(res, nfi);
		}
	}

	// Расчет подачи насоса
	private: System::Void buttonPN_Enter_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear results
		textBoxPN_resVg->Text ="";
		textBoxPN_resQ->Text ="";

		// vars init
		double Q, n, eta, Vg, res;
		Q = getText(textBoxPN_Q);
		n = getText(textBoxPN_n);
		eta = getText(textBoxPN_eta);
		Vg = getText(textBoxPN_Vg);

		// расчет объема рабочей камеры насоса
		if (Q > 0 && eta > 0 && n > 0) {
			res = Math::Round(Q * 1000 / n / eta, COUNT_DECIMAL);
			textBoxPN_resVg->Text = Convert::ToString(res, nfi);
		}

		// расчет подачи насоса
		if (Vg > 0 && eta > 0 && n > 0) {
			res = Math::Round((Vg * n) / 1000 * eta, COUNT_DECIMAL);
			textBoxPN_resQ->Text = Convert::ToString(res, nfi);
		}
	}

	// Расчет оборотов гидромотора
	private: System::Void buttonOG_Enter_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear results
		textBoxOG_resn->Text ="";

		// vars init
		double Q, eta, Vg, res;
		Q = getText(textBoxOG_Q);
		Vg = getText(textBoxOG_Vg);
		eta = getText(textBoxOG_eta);
		
		// расчет кол-ва оборотов гидромотора
		if (Q > 0 && eta > 0 && Vg > 0) {
			res = Math::Round(Q / (Vg / 1000) * eta, COUNT_DECIMAL);
			textBoxOG_resn->Text = Convert::ToString(res, nfi);
		}
	}

	// расчет крутящего момента гидромотора
	private: System::Void buttonKMG_Enter_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear results
		textBoxKMG_resM->Text ="";
		textBoxKMG_resP->Text ="";
		textBoxKMG_resVg->Text ="";

		// vars init
		double M, Vg, P, eta, k, res;
		M = getText(textBoxKMG_M);
		Vg = getText(textBoxKMG_Vg);
		P = getText(textBoxKMG_P);
		eta = getText(textBoxKMG_eta);

		// расчет момента
		if (Vg > 0 && P > 0 && eta > 0) {
			if (radioButtonKMG_reskgm->Checked) {
				k = 1;
			}
			else {
				k = G;
			}
			res = Math::Round((1.59 * Vg * P * eta) / 1000 * k, COUNT_DECIMAL);
			textBoxKMG_resM->Text = Convert::ToString(res, nfi);
		}

		// расчет давления
		if (Vg > 0 && M > 0 && eta > 0) {
			res = Math::Round(M / (1.59 * Vg * eta) * 1000, COUNT_DECIMAL);
			textBoxKMG_resP->Text = Convert::ToString(res, nfi);
		}

		// расчет объема
		if (P > 0 && M > 0 && eta > 0) {
			res = Math::Round(M / (1.59 * P * eta) * 1000, COUNT_DECIMAL);
			textBoxKMG_resVg->Text = Convert::ToString(res, nfi);
		}
	}

	// смена ед.измерения момента
	private: System::Void radioButtonKMG_reskgm_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBoxKMG_resM->Text !="") {
			double res, k;
			res = getText(textBoxKMG_resM);

			if (radioButtonKMG_reskgm->Checked) {
				k = 1 / G;
			}
			else {
				k = G;
			}
			res = Math::Round(res * k, COUNT_DECIMAL);
			textBoxKMG_resM->Text = Convert::ToString(res, nfi);
		}
	}

	// смена ед.измерения момента
	private: System::Void radioButtonKMV_resMkgm_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBoxKMV_resM->Text !="") {
			double res, k;
			res = getText(textBoxKMV_resM);

			if (radioButtonKMV_resMkgm->Checked) {
				k = 1 / G;
			}
			else {
				k = G;
			}
			res = Math::Round(res * k, COUNT_DECIMAL);
			textBoxKMV_resM->Text = Convert::ToString(res, nfi);
		}
	}

	// расчет крутящего момента на валу (мощность и обороты)
	private: System::Void buttonKMV_Enter_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear results
		textBoxKMV_resM->Text ="";

		// vars init
		double N, n, k, res;
		N = getText(textBoxKMV_N);
		n = getText(textBoxKMV_nn);

		// расчет момента
		if (N > 0 && n > 0) {
			if (radioButtonKMV_resMkgm->Checked) {
				k = G;
			}
			else {
				k = 1;
			}
			res = Math::Round(9555 * N / n / k, COUNT_DECIMAL);
			textBoxKMV_resM->Text = Convert::ToString(res, nfi);
		}
	}

	// Расчёт объёма пластинчатого насоса по геометрическим размерам
	private: System::Void buttonOPN_Enter_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear results
		textBoxOPN_resV->Text ="";

		// vars init
		double W, D, L, res;
		W = getText(textBoxOPN_W);
		D = getText(textBoxOPN_D);
		L = getText(textBoxOPN_L);

		// расчет объема
		if (W > 0 && D > 0 && L > 0) {
			if (L > D) {
				res = Math::Round(12 * W * (L + D) / 4 * (L - D) / 2, COUNT_DECIMAL);
				textBoxOPN_resV->Text = Convert::ToString(res, nfi);
			} else {
				textBoxOPN_D->Focus();
				MessageBox::Show(L"Длина (L) должна быть больше диаметра (D)", L"Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	// Расчёт объёма шестеренного насоса по геометрическим размерам
	private: System::Void buttonOShN_Enter_Click(System::Object^ sender, System::EventArgs^ e) {
		// clear results
		textBoxOShN_resV->Text ="";

		// vars init
		double W, D, L, res;
		W = getText(textBoxOShN_W);
		D = getText(textBoxOShN_D);
		L = getText(textBoxOShN_L);

		// расчет объема
		if (W > 0 && D > 0 && L > 0) {
			if (L > D && L < 2 * D) {
				res = Math::Round(6 * W * (2 * D - L) * (L - D) / 2, COUNT_DECIMAL);
				textBoxOShN_resV->Text = Convert::ToString(res, nfi);
			}
			else {
				textBoxOShN_D->Focus();
				MessageBox::Show(L"Длина (L) должна быть больше диаметра (D), и меньше двойного диаметра", L"Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void TabMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ToolStripMenuItem^ clickedMenuItem = safe_cast<ToolStripMenuItem^>(sender);
		tabControl1->SelectedIndex = Convert::ToInt16(clickedMenuItem->Tag);
	}
};
}