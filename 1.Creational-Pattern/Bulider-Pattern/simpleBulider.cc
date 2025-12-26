#include <iostream>

struct HtmlElement
{
    std::string name;
    std::string text;

    std::vector<HtmlElement> elements;

    HtmlElement() = default;
    HtmlElement(const std::string& name, const std::string& text)
        : name(name), text(text) {};

    std::string str(int indent = 0) const
    {
        std::string result(indent, ' ');
        result += "<" + name + ">" + text;
        for (const auto& child : elements)
        {
            result += "\n" + child.str(indent + 2);
        }
        result += "\n" + std::string(indent, ' ') + "</" + name + ">";
        return result;
    }
};

struct HtmlBuilder
{
    HtmlElement root;
    HtmlBuilder(const std::string& root_name)
    {
        root.name = root_name;
    }

    void add_child(std::string child_name, std::string child_text)
    {
        HtmlElement e{child_name, child_text};

        root.elements.emplace_back(e);
    };

    std::string str(){return root.str();}
};

int main()
{
    HtmlBuilder bd{"ul"};
    bd.add_child("li", "hello");
    bd.add_child("li", "world");
    
    std::cout << bd.str() << std::endl;

    return 0;
}