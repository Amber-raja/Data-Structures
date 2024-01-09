#include <iostream>
#include <string>

using namespace std;

class Movie
{
public:
	int movieID;
	string title;
	string genre;
	double ratings;
	Movie *left;
	Movie *right;

public:
	// Define the constructor
	Movie(int movieID, string title, string genre, double ratings)
	{
		this->movieID = movieID;
		this->title = title;
		this->genre = genre;
		this->ratings = ratings;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class MovieRecommendationSystem
{
public:
	Movie *root;

public:
	// Define the constructor
	MovieRecommendationSystem()
	{
		this->root = nullptr;
	}

	// Insert a movie into the BST
	Movie *insertMovie(Movie *node, int movieID, string title, string genre, double ratings)
	{
		if (node == nullptr)
		{
			return new Movie(movieID, title, genre, ratings);
		}

		if (movieID < node->movieID)
		{
			node->left = insertMovie(node->left, movieID, title, genre, ratings);
		}
		else if (movieID > node->movieID)
		{
			node->right = insertMovie(node->right, movieID, title, genre, ratings);
		}

		return node;
	}

	void recommendMoviesByGenre(Movie *node, string genre)
	{
		if (node == nullptr)
		{
			return;
		}

		recommendMoviesByGenre(node->left, genre);

		if (node->genre == genre)
		{
			cout << "Movie ID: " << node->movieID << ", Title: " << node->title << ", Genre: " << node->genre << ", Ratings: " << node->ratings << endl;
		}

		recommendMoviesByGenre(node->right, genre);
	}

	Movie *findMinValueNode(Movie *node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}
	Movie *deleteMovieByID(Movie *node, int movieID)
	{
		if (node == nullptr)
		{
			return node;
		}

		if (movieID < node->movieID)
		{
			node->left = deleteMovieByID(node->left, movieID);
		}
		else if (movieID > node->movieID)
		{
			node->right = deleteMovieByID(node->right, movieID);
		}
		else
		{
			if (node->left == nullptr)
			{
				Movie *temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr)
			{
				Movie *temp = node->left;
				delete node;
				return temp;
			}

			Movie *temp = findMinValueNode(node->right);

			node->movieID = temp->movieID;
			node->title = temp->title;
			node->genre = temp->genre;
			node->ratings = temp->ratings;

			node->right = deleteMovieByID(node->right, temp->movieID);
		}
		return node;
	}
	void display_Movies(Movie *node)
	{
		if (node != nullptr)
		{
			display_Movies(node->left);
			cout << "Movie ID: " << node->movieID << ", Title: " << node->title << ", Genre: " << node->genre << ", Ratings: " << node->ratings << endl;
			display_Movies(node->right);
		}
	}
};

int main()
{
	MovieRecommendationSystem engine;
	int choice;
	while (true)
	{
		cout << "Menu:\n";
		cout << "1. Add a Movie\n";
		cout << "2. Delete a Movie by ID\n";
		cout << "3. Recommend Movies by Genre\n";
		cout << "4. Display Movies Sorted by Ratings\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int movieID;
			string title, genre;
			double ratings;
			cout << "Enter Movie ID: ";
			cin >> movieID;
			cin.ignore(); // Clear newline character from the buffer
			cout << "Enter Movie Title: ";
			getline(cin, title);
			cout << "Enter Movie Genre: ";
			getline(cin, genre);
			cout << "Enter Ratings: ";
			cin >> ratings;

			engine.root = engine.insertMovie(engine.root, movieID, title, genre, ratings);
			cout << "Movie added successfully!" << endl;
			break;
		}
		case 2:
		{
			int deleteID;
			cout << "Enter Movie ID to delete: ";
			cin >> deleteID;
			engine.root = engine.deleteMovieByID(engine.root, deleteID);
			cout << "Movie with ID " << deleteID << " deleted successfully!" << endl;
			break;
		}
		case 3:
		{
			string genre;
			cout << "Enter your favorite genre: ";
			cin.ignore(); // Clear newline character from the buffer
			getline(cin, genre);
			cout << "Recommended Movies in Genre '" << genre << "':" << endl;
			engine.recommendMoviesByGenre(engine.root, genre);
			break;
		}
		case 4:
			cout << "Movies Sorted by Ratings:" << endl;
			engine.display_Movies(engine.root);
			break;
		case 5:
			cout << "Exiting the program." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}
	return 0;
}
