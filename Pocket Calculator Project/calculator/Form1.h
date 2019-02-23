#pragma once
#include <sstream>
#include <string>
#include <math.h>
using namespace std;
namespace calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		static double num2 = 0;
		static double num1 = 0;
		static double nextDiv = 0.1;
		static double ZecimalMDS = 0;
		static double SquaringAUX = 0;
		static System::String^ aux_name = "";
		static short MultiplicationCounter, DivisionCounter, SquaringRound=0;
		static bool addition, subtraction, squaring, zecimalFlag, gettingSecondaryValueD,
			gettingSecondaryValueM, squareRoot, SquaringRequiredFirst, SquaringSecondaryValue = false;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button21;

	private: System::Windows::Forms::Button^  button4;
	public: 
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(12, 31);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(155, 20);
			this->textBox2->TabIndex = 0;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(45, 149);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(27, 22);
			this->button3->TabIndex = 1;
			this->button3->Text = L"1";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(235, 99);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(37, 36);
			this->button4->TabIndex = 2;
			this->button4->Text = L"+";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Operation:";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(189, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Result:";
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(192, 31);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(80, 20);
			this->textBox3->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(173, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"=";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(235, 141);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(37, 38);
			this->button5->TabIndex = 7;
			this->button5->Text = L"=";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(235, 191);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(37, 36);
			this->button6->TabIndex = 8;
			this->button6->Text = L"C";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(12, 149);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(27, 22);
			this->button7->TabIndex = 9;
			this->button7->Text = L"0";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(78, 149);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(27, 22);
			this->button8->TabIndex = 10;
			this->button8->Text = L"2";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(111, 149);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(27, 22);
			this->button9->TabIndex = 11;
			this->button9->Text = L"3";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(12, 177);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(27, 22);
			this->button10->TabIndex = 12;
			this->button10->Text = L"4";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(45, 177);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(27, 22);
			this->button11->TabIndex = 13;
			this->button11->Text = L"5";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(78, 177);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(27, 22);
			this->button12->TabIndex = 14;
			this->button12->Text = L"6";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(111, 177);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(27, 22);
			this->button13->TabIndex = 15;
			this->button13->Text = L"7";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(12, 205);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(27, 22);
			this->button14->TabIndex = 16;
			this->button14->Text = L"8";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(45, 205);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(27, 22);
			this->button15->TabIndex = 17;
			this->button15->Text = L"9";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(192, 99);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(37, 36);
			this->button16->TabIndex = 18;
			this->button16->Text = L"-";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(192, 141);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(37, 36);
			this->button17->TabIndex = 19;
			this->button17->Text = L"X";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(192, 191);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(37, 36);
			this->button18->TabIndex = 20;
			this->button18->Text = L"/";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(149, 99);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(37, 36);
			this->button19->TabIndex = 21;
			this->button19->Text = L"^";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Form1::button19_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(78, 205);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(27, 22);
			this->button20->TabIndex = 22;
			this->button20->Text = L",";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(149, 141);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(37, 36);
			this->button21->TabIndex = 23;
			this->button21->Text = L"Sqrt";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &Form1::button21_Click);
			// 
			// Form1
			// 
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"MyCalculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
//LABEL1
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
//LABEL2
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
// = BUTTON
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				textBox3->Text=aux_name;
				ProcessOperations();
				if(num2>0) // put that value to num1, because it means there was a multiplication
					//division or squaring op that was effectuated.
				{
					num1+=num2;
					num2=0;
				}
			    textBox3->Text += SConverter(num1);
		 }
// C BUTTON
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 num1=0;
			 num2=0;
			 textBox3->Text = "";
			 textBox2->Text = "";
			 zecimalFlag = false;
			 addition = false;
			 subtraction = false;
			 squaring = false;
			 ZecimalMDS=0;
			 gettingSecondaryValueM=false;
			 gettingSecondaryValueD=false;
			 squareRoot=false;
			 SquaringAUX = 0;
			 aux_name="";
			 MultiplicationCounter=0;
			 DivisionCounter=0;
			 SquaringSecondaryValue=false;
			 SquaringRequiredFirst = false;
			 SquaringRound = 0;
		 }
// + BUTTON
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				textBox2->Text += " + ";
				ProcessOperations();
				addition = true;
				textBox3->Text = SConverter(num1);
			 }
// / BUTTON
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
			textBox2->Text += " / ";
			//This flag need to be placed here:
			 DivisionCounter++;
			 gettingSecondaryValueD=true;
			 if(squaring && MultiplicationCounter>0)
			{
				SquaringRequiredFirst = true;
			}
			 //This function needs to be called after turning the flags on.
			 ProcessOperations();
			 textBox3->Text = SConverter(num1);
		 }
// ^ BUTTON
private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
        	textBox2->Text += " ^ ";
			//This flag need to be placed here:
			 squaring=true;
			 SquaringSecondaryValue=true;
			 SquaringRound++;
			 if(MultiplicationCounter>0 || DivisionCounter>0)
			{
				SquaringRequiredFirst = true;
			}
			 else
			{
				SquaringRequiredFirst = false;
			}
			 //This function needs to be called after turning the flags on.
			 ProcessOperations();
			 textBox3->Text = SConverter(num1);
		 }
// - BUTTON
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
			textBox2->Text += " - ";
			if(addition&&subtraction) // if 3+-2, don't do 3+2, do 3-2.
			{
				addition=false;
			}
			ProcessOperations();
			subtraction = true;
			textBox3->Text = SConverter(num1);
		 }
// X BUTTON
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text += " X ";
			 //This flag need to be placed here:
			 MultiplicationCounter++;
			 gettingSecondaryValueM=true;
			 if(squaring && DivisionCounter>0)
			{
				SquaringRequiredFirst = true;
			}
			//This function needs to be called after turning the flags on.
			 ProcessOperations();
			 textBox3->Text = SConverter(num1);
		 }
//OPERATIONS:
private: void AdditionOP ()
		{
			if(MultiplicationCounter<1 && DivisionCounter<1 && !squaring && !squareRoot) //don't do addition in front of multiplication,
				//division
			{
				num1+=num2;
				num2=0;
			}
			addition = false;
			zecimalFlag = false;
		}
private: void SubtractionOP ()
		{
			if(MultiplicationCounter<1 && DivisionCounter<1 && !squaring) // don't do subtraction in front of multiplication,
				//division
			{
				num1-=num2;
				num2=0;
			}
			subtraction = false;
			zecimalFlag = false;
		}
private: void DivisionOP (double value)
		{
			if(value == 0)
			{
				DivisionCounter--;
				num2=0;
				return;
			}
			if(num2 == 0)
			{
				DivisionCounter--;
				return;
			}
			num2/=value;
			DivisionCounter--;
			zecimalFlag = false;
		}
private: void MultiplicationOP ()
		{
			if(ZecimalMDS == 0)
			{
				MultiplicationCounter--;
				num2=0;
				return;
			}
			if(num2 == 0)
			{
				MultiplicationCounter--;
				return;
			}
			num2=num2*ZecimalMDS;
			MultiplicationCounter--;
			zecimalFlag = false;
		}
private: void SpecialMultiplicationOP()
		{
			 if(num2 == 0)
			{
				MultiplicationCounter--;
				num1=0;
				return;
			}
			if(num1 == 0)
			{
				MultiplicationCounter--;
				return;
			}
			num1=num1*num2;
			MultiplicationCounter--;
			zecimalFlag = false;
		}
private: void SpecialDivisionOP(double value)
		 {
			 if(value == 0)
			{
				DivisionCounter--;
				num1=0;
				return;
			}
			if(num1 == 0)
			{
				DivisionCounter--;
				return;
			}
			num1/=value;
			DivisionCounter--;
			zecimalFlag = false;
		}
private: double SquaringOP (double num2, int value)
		{
			double res = num2;
			if(value==0)
			{
				return 1;
			}
			else if(value==1)
			{
				//the value of num2 won't be changed
				return num2;
			}
			for(int i=1; i<value; i++)
			{
				res*=num2;
			}
			squaring = false;
			zecimalFlag = false;
			return res;
		} //END OF OPERATIONS
private: double SquareRootOP (double value)
			 {
				 squareRoot=false;
				 return sqrt(value);
			 }
// 0 BUTTON
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text += "0";
			 int ThisButtonValue = 0;
			 DoSomething(ThisButtonValue);
		 }
// 1 BUTTON
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				textBox2->Text += "1";
				int ThisButtonValue = 1;
			    DoSomething(ThisButtonValue);
			}
// 2 BUTTON
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			    textBox2->Text += "2";
				int ThisButtonValue = 2;
			    DoSomething(ThisButtonValue);
		 }
// 3 BUTTON
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text += "3";
			 int ThisButtonValue = 3;
			 DoSomething(ThisButtonValue);
		 }
// 4 BUTTON
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text += "4 ";
			 int ThisButtonValue = 4;
			 DoSomething(ThisButtonValue);
		 }
// 5 BUTTON
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text += "5";
			 int ThisButtonValue = 5;
			 DoSomething(ThisButtonValue);
		 }
// 6 BUTTON
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text += "6";
			 int ThisButtonValue = 6;
			 DoSomething(ThisButtonValue);
		 }
// 7 BUTTON
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text += "7";
			 int ThisButtonValue = 7;
			 DoSomething(ThisButtonValue);
		 }
// 8 BUTTON
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text += "8";
			 int ThisButtonValue = 8;
			 DoSomething(ThisButtonValue);
		 }
// 9 BUTTON
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text += "9";
			 int ThisButtonValue = 9;
			 DoSomething(ThisButtonValue);
		 }
//NUMBER CONCATENER
private:int concat(double x, int y) 
	{
		int temp = y;
		if(y==0)
		{
			return x*10;
		}
		while (y != 0) {
		    x *= 10;
		    y /= 10;
		}
		return x + temp;
	}
//ZECIMAL CONCATENER
private:double ZecimalConcatener(int addedZecimal)
{
	double ZecimalPart = 0; 
	ZecimalPart = addedZecimal*nextDiv;
	nextDiv *= 0.1;
	return ZecimalPart;
}
//INTEGER TO SYSTEM::STRING CONVERTER
private: System::String^ SConverter(double result)
		{
			stringstream ss;
			ss << result;
			string tmp = ss.str();
			System::String^ name = gcnew String (tmp.c_str());
			return name;
		}
//Get numb2 value and effect primary operations
private: void DoSomething(int ThisButtonValue)
			{
				if(num2==0 && MultiplicationCounter<1 && DivisionCounter<1 && !squaring)
				{
					if(!zecimalFlag)
					{
						num2+=ThisButtonValue;
					}
					else
					{
						num2+=ZecimalConcatener(ThisButtonValue);
					}
				}
				else if (MultiplicationCounter<1 && DivisionCounter<1 && !squaring)
				{
					if(!zecimalFlag)
					{
						num2=concat(num2, ThisButtonValue);
					}
					else
					{
						num2+=ZecimalConcatener(ThisButtonValue);
					}
				}
				if(MultiplicationCounter>0 && !squaring && !squareRoot)
				{
						if(ZecimalMDS==0 && !zecimalFlag)
						{
							ZecimalMDS+=ThisButtonValue;
						}
						else if (!zecimalFlag)
						{
							ZecimalMDS=concat(ZecimalMDS, ThisButtonValue);
						}
						else
						{
							ZecimalMDS+=ZecimalConcatener(ThisButtonValue);
						}
					gettingSecondaryValueM=false;
				}
				else if(DivisionCounter>0 && !squaring && !squareRoot)
				{
					if(ZecimalMDS==0 && !zecimalFlag)
					{
						ZecimalMDS+=ThisButtonValue;
					}
					else if (!zecimalFlag)
					{
						ZecimalMDS=concat(ZecimalMDS, ThisButtonValue);
					}
					else
					{
						ZecimalMDS+=ZecimalConcatener(ThisButtonValue);
					}
					gettingSecondaryValueD=false;
				}
				else if(squaring)
				{
					if(MultiplicationCounter<1 && DivisionCounter<1)
					{
						if(ZecimalMDS==0 && !zecimalFlag)
						{
							ZecimalMDS+=ThisButtonValue;
						}
						else if (!zecimalFlag)
						{
							ZecimalMDS=concat(ZecimalMDS,ThisButtonValue);
						}
						else
						{
							ZecimalMDS += ZecimalConcatener(ThisButtonValue);
						}
					}
					else
					{
						if(SquaringAUX==0 && !zecimalFlag)
						{
							SquaringAUX+=ThisButtonValue;
						}
						else if (!zecimalFlag)
						{
							SquaringAUX=concat(SquaringAUX,ThisButtonValue);
						}
						else
						{
							SquaringAUX+=ZecimalConcatener(ThisButtonValue);
						}
					}
					SquaringSecondaryValue=false;
				}
			}
// , BUTTON
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
			if(!zecimalFlag)
			{
				zecimalFlag=true;
				textBox2->Text+=",";
				nextDiv=0.1;
			}
		 }
//PROCESS THE OPERATIONS:
private: void ProcessOperations()
			{
				if((addition || num1==0) && MultiplicationCounter<1 && DivisionCounter<1 && !squaring && !squareRoot)
				{
					AdditionOP();
				}
				else if(subtraction && MultiplicationCounter<1 && DivisionCounter<1 && !squaring && !squareRoot)
				{
					SubtractionOP();
				}
				if(MultiplicationCounter>0 && !squareRoot && !squaring)
				{
					if(!gettingSecondaryValueM || MultiplicationCounter>1) //put this condition to avoid multiplication
						//with default 0 value;
					{
						MultiplicationOP(); //MultiplicationCounter will be decreased in this function;
					}
					if(addition && MultiplicationCounter<1 && DivisionCounter<1)
					{
						AdditionOP();
					}
					else if(subtraction && MultiplicationCounter<1 && DivisionCounter<1)
					{
						SubtractionOP();
					}
					if(MultiplicationCounter<1 && DivisionCounter<1)
					{
						num1+=num2;
						num2=0;
					}
					ZecimalMDS=0;
				}
				else if(DivisionCounter>0 && !squareRoot && !squaring)
				{
					if(!gettingSecondaryValueD || DivisionCounter>1) //put this condition to avoid
						//division with default 0 value;
					{
						DivisionOP(ZecimalMDS); //DivisionCounter will be decreased in this function;
					}
					if(addition && MultiplicationCounter<1 && DivisionCounter<1)
					{
						AdditionOP();
					}
					else if(subtraction && MultiplicationCounter<1 && DivisionCounter<1)
					{
						SubtractionOP();
					}
					if(MultiplicationCounter<1 && DivisionCounter<1)
					{
						num1+=num2;
						num2=0;
					}
					ZecimalMDS=0;
				}
				else if(squaring && !SquaringSecondaryValue)
				{
					if(!SquaringRequiredFirst)
					{
						
						if(SquaringRound<2&& (MultiplicationCounter<1 || gettingSecondaryValueM) && (DivisionCounter<1 || gettingSecondaryValueD))
						{
							num2=SquaringOP(num2,(int)ZecimalMDS);
						}
						else
						{
							num2=SquaringOP(ZecimalMDS,(int)SquaringAUX); //will take the integer part of ZecimalMDS
							if(MultiplicationCounter>0)
							{
								SpecialMultiplicationOP();
								num2=0;
							}
							else if(DivisionCounter>0)
							{
								SpecialDivisionOP(num2);
								num2=0;
							}
						}
						if(num1==0 && MultiplicationCounter<1 && DivisionCounter<1)
						{
							num1+=num2;
							num2=0;
						}
						
						ZecimalMDS=0;
						aux_name="aprox. ";
					}
					else
					{
						ZecimalMDS=SquaringOP(ZecimalMDS,(int)SquaringAUX);
						if(MultiplicationCounter>0 &&!gettingSecondaryValueM)
						{
							if(!gettingSecondaryValueM || MultiplicationCounter>1)
							{
								MultiplicationOP();
							}
						}
						else if(DivisionCounter>0 && !gettingSecondaryValueD)
						{
							if(!gettingSecondaryValueD || DivisionCounter>1)
							{
								DivisionOP(ZecimalMDS);
							}
						}
						if(MultiplicationCounter<1 && DivisionCounter<1)
						{
							num1+=num2;
							num2=0;
						}
						ZecimalMDS=0;
						SquaringAUX=0;
						aux_name="aprox. ";
					}
				}
				else if(squareRoot)
				{
					if(MultiplicationCounter>0 || DivisionCounter>0 || squaring)
					{
						ZecimalMDS = SquareRootOP(ZecimalMDS);
						num2+=ZecimalMDS;
						num1+=num2;
						num2=0;
						ZecimalMDS=0;
					}
					else
					{
						num2=SquareRootOP(num2);
						num1+=num2;
						num2=0;
					}
				}
				zecimalFlag=false;
			}
//SQRT BUTTON
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text += "<-Sqrt";
			 //This flag need to be placed here:
			 squareRoot=true;
			 ProcessOperations();
			 textBox3->Text = SConverter(num1);
		 }
};
}

