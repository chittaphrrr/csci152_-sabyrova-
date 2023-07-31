#include <ostream>
#include "csci152_student.h"

csci152_student::csci152_student(
			std::string nm,
			std::initializer_list<unsigned int> assignments,
			std::initializer_list<double> quizzes,
			double final_exam
	):
    num_of_assignments(assignments.size()),
	num_of_quizzes(quizzes.size()),
	assignment_scores(new unsigned int[assignments.size()]),
	quiz_scores(new double[quizzes.size()])
    {
        name = nm;
    	final_exam_score = final_exam;
    
    	int count = 0;
    	for (int element : assignments)
    	{
    		assignment_scores[count] = element;
    		count++;
    	}
    	count = 0;
    	for (double element : quizzes)
    	{
    		quiz_scores[count] = element;
    		count++;
    	}
    }

	/*
	 * Copy constructor
	 */
csci152_student::csci152_student(const csci152_student& other):
    name(other.name),
    final_exam_score(other.final_exam_score),
    num_of_assignments(other.num_of_assignments),
	num_of_quizzes(other.num_of_quizzes),
	assignment_scores(new unsigned int[num_of_assignments]),
	quiz_scores(new double[num_of_quizzes])
    {
    	for (size_t count = 0; count < num_of_assignments; count++)
    	{
    		assignment_scores[count] = other.assignment_scores[count];	
    	}
    
    	for (size_t count = 0; count < num_of_quizzes; count++)
    	{
    		quiz_scores[count] = other.quiz_scores[count];	
    	}
    }

	/*
	 * Copy assignment - be careful to properly dispose of allocated memory for this
	 * before overwriting with values from other
	 */
csci152_student& csci152_student::operator=(const csci152_student& other)
    {
        name = other.name;
    	final_exam_score = other.final_exam_score;
        num_of_quizzes = other.num_of_quizzes;
        num_of_assignments = other.num_of_assignments;
        
        delete[] assignment_scores;
        assignment_scores = new unsigned int[num_of_assignments]; 
        delete[] quiz_scores;
        quiz_scores = new double[num_of_quizzes];
    
    	for (size_t count = 0; count < num_of_assignments; count++)
    	{
    		assignment_scores[count] = other.assignment_scores[count];    	
    	}
    	for (size_t count = 0; count < num_of_quizzes; count++)
    	{
    		quiz_scores[count] = other.quiz_scores[count];
    	}
        
    	return *this;
    }

	/*
	 * Name getter
	 */
std::string csci152_student::get_name() const
    {
        return name;
    }

	/*
	 * Name setter
	 */
void csci152_student::change_name(std::string new_name)
    {
        name = new_name;
    }

	/*
	 * Calculates the total assignment percentage between 0.0 and 100.0.
	 * Although individual assignment scores have integer values, the 
	 * final percentage should be a floating-point number
	 */
double csci152_student::calculate_assignment_perc() const
    {
        double sum = 0;
    	for (int numerus = 0; numerus < num_of_assignments; numerus++)
    	{
    		sum += assignment_scores[numerus];	
    	}
    	sum /= num_of_assignments;
        
    	return sum;
    }

	/*
	 * Calculates the total quiz percentage between 0.0 and 100.0, dropping
	 * the lowest quiz score.
	 * Note that individual quiz scores are between 0 and 20.0
	 */
double csci152_student::calculate_quiz_perc() const
    {
        double sum = 0, min_quiz = quiz_scores[0];
    	int index = 0;
    	for (int count = 0; count < num_of_quizzes; count++)
    	{
    		if (min_quiz > quiz_scores[count]) 
    		{
    			min_quiz = quiz_scores[count];
    			index = count;
    		}
            sum += quiz_scores[count];
    	}
    	sum -= quiz_scores[index];
    	sum = 5*sum/(num_of_quizzes - 1);
        
    	return sum;
    }


	/*
	 * Returns the value stored in final_exam_score
	 */
double csci152_student::get_final_exam_perc() const
    {
        return final_exam_score;
    }

	/*
	 * Calculates the total course grade as a percent, using the weighting from
	 * the syllabus
	 */
double csci152_student::calculate_course_perc() const
    {
        double sum; 
        sum = 35*calculate_quiz_perc() + 35*calculate_assignment_perc() + 30*final_exam_score;
        sum /= 100;
	   return sum;
    }

	/*
	 * Destructor - don't forget you need to delete anything you explicitly allocated
	 */
csci152_student::~csci152_student()
    {
        delete [] assignment_scores;
        delete [] quiz_scores;
    }