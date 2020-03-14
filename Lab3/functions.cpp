#include "functions.h"





// ���������� ���-�� ��������, ����������� ����
int amount_of_zero_cells_static(int(&arr)[3][2]) {
	int count = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[j][i] == 0) {
				count++;
				break;
			}
		}
	}
	return count;
}

// ����� ������, � ������� ��������� ����� ������� ����� ���������� ���������.
int num_of_longest_line_static(int(&arr)[3][2]) {
	int num_of_most_longest = -1;			// ������ ����� ����� ������� ������
	int most_longest = 0;	// ������ ����� ���� ������
	int now = -1;			// ����� ������, ������� ������ ��������������
	int now_longest = 0;	// ����� ������, ������� ������ ��������������
	for (int i = 0; i < 3; i++) {
		int num_repeating = arr[i][0];  // ������ �����, ������� ������������ � ������������
		for (int j = 1; j < 2; j++) {
			if (num_repeating == arr[i][j] and now_longest == 0) // ����� ���������� ������ �����������
			{
				now_longest++;
				now = i;
			}
			else {
				if (num_repeating = arr[i][j] and now_longest != 0) // ���������� ������������
				{
					now_longest++;
				}
				else
					if (num_repeating != arr[i][j] and now_longest != 0) // ����� ���������� �����������
					{
						/*
							�������� �� ������� ������������������ ����� �������
							���� �������� - ���������� �� � most_longest 
												� � num_of_most_longest
						*/
						if (most_longest < now_longest) 
						{
							most_longest = now_longest;
							num_of_most_longest = now;
							now_longest = 0;
							now = -1;
						}
					}
			}
		}
		/*
			�������� �� ������� ������������������ ����� �������
			���� �������� - ���������� �� � most_longest
							� � num_of_most_longest
		*/
		if (most_longest < now_longest) {
			most_longest = now_longest;
			num_of_most_longest = now;
			now_longest = 0;
			now = -1;
		}
	}
	if (num_of_most_longest != -1)
		return num_of_most_longest;
	else
	{
		throw NO_REPEATING;
		return num_of_most_longest;
	}
}


void writeMatrixToFile(int(&arr)[3][2], std::ofstream& file) {
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 2; j++) {
			if (j != 2 - 1)
				file << arr[i][j] << " ";
			else
			{
				file << arr[i][j];
				file << std::endl;
			}
		}
	file << "���������� ��������, ���������� ���� �� ���� ������� �������: " << amount_of_zero_cells_static(arr) << std::endl;
	try
	{
		file << "����� ������, � ������� ��������� ����� ������� ����� ���������� ���������: " << num_of_longest_line_static(arr) << std::endl;
	}
	catch (ExceptionLab e)
	{
		file << "����� ������ �� �������" << std::endl;
	}
	file << std::endl << std::endl;
}