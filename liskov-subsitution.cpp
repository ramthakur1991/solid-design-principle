#include<iostream>
using namespace std;


class Rectangle {
    protected:
        int width, height;
    public:
        Rectangle(int width, int height): width(width), height(height) {}

        int getWidth() const {
            return width;
        }

        virtual void setWidth(int width) {
            Rectangle::width=width;
        }

        int getHeight() const {
            return height;
        }

        virtual void setHeight(int height) {
            Rectangle::height=height;
        }

        int area() const {
            return width*height;
        }
};


/**
 * What I intendendly have done here is just violate the liskove subsitution principle,
 * which states that if you have a function which takes a base class,
 * any derive class should be able to be subsituted into the function without any problem.
 */
class Square : public Rectangle {
    public:
        Square(int size): Rectangle(size, size) {}

        void setWidth(int width) override {
            this->width = this->height = width;
        }

        void setHeight(int height) override {
            this->width = this->height = height;
        }

};

void process(Rectangle &r) {
    int w = r.getWidth();
    r.setHeight(10);

    cout << "Expected area = " << (w*10) << ", got " << r.area() << endl;
}

int main() {
    Rectangle r{3,4};
    process(r);

    /**
     * the process should return the 50 where it's returning the 100 as we have broken the setter 
     * method by setting the both height and width.
     * 
     * So question how we can fix this.
     * My argument here is that instead of inheriting the sequare from rectangle is not the best idea.
     * in term of language sequare is in fact a retangle. we can have different ways like factories or have a boolean 
     * flag indicate wheather it'sequare or not.
     */
    Square sq{5};
    process(sq);
    return 0;
}