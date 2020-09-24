#ifndef BRAIN
#define BRAIN

#include<vector>

class MutationSettings {};

template<typename T>
class Brain {
public:
	virtual std::vector<int> make_a_move(std::vector<T> sensor_data) = 0;

	virtual void mutate() = 0;

	virtual bool check_ally(Brain<T>* other) = 0;

	virtual int get_size() = 0;
};

#endif
