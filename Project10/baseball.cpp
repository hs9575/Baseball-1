#include <stdexcept>
#include <string>

using namespace std;
struct Result {
	int solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& question)
		: question(question)
	{
	}

	Result guess(std::string guessNumber)
	{
		assertIllegalArgument(guessNumber);
		int bcnt = getBallCount(guessNumber);
		int scnt = getStrikeCount(guessNumber);
		bool ret = (scnt == 3) ? true : false;
		Result result = { ret,scnt,bcnt };
		return result;
	}

private:
	void assertIllegalArgument(std::string guessNumber)
	{
		if (guessNumber == "")
			throw std::invalid_argument("�� �ʿ�");
		if (guessNumber.length() != 3)
		{
			throw std::invalid_argument("�ڸ��� ����");
		}
		if (isIncludeChar(guessNumber))
		{
			throw std::invalid_argument("���� ����");
		}
		if (isDuplicatedNumber(guessNumber))
		{
			throw std::invalid_argument("�ߺ� ����");
		}
	}

	bool isDuplicatedNumber(const std::string& guess_number) {
		if (guess_number[0] == guess_number[1] ||
			guess_number[0] == guess_number[2] ||
			guess_number[1] == guess_number[2])
			return true;
		return false;
	}

	bool isIncludeChar(const std::string& string) {
		for (char ch : string) {
			if (ch < '0' || ch > '9')
				return true;
		}
		return false;
	}

	int getStrikeCount(string guessNumber)
	{
		int result = 0;
		for (int i = 0; i < 3; i++)
		{
			int index = question.find(guessNumber[i]);
			if (index == -1)continue;
			if (index != i)continue;
			result++;
		}
		return result;
	}
	int getBallCount(string guessNumber)
	{
		int result = 0;
		for (int i = 0; i < 3; i++)
		{
			int index = question.find(guessNumber[i]);
			if (index == -1)continue;
			if (index == i)continue;
			result++;
		}
		return result;
	}
	
	string question;
};
