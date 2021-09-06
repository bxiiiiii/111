#include <string>
#include <iostream>

class Quote
{
public:
        Quote() = default;
        Quote(const std::string &b, double p):
                        bookNo(b), price(p) { }
        std::string isbn() const { return bookNo; }
        virtual double net_price(std::size_t n) const { return n*price; }
        virtual void debug();
        virtual ~Quote() = default;

private:
        std::string bookNo;

protected:
        double price = 0.0;
};

class Disc_quote : public Quote
{
public:
        Disc_quote() = default;
        Disc_quote(const std::string &str, double p, std::size_t q, double d) :
                    Quote(str, p), quanlity(q), discount(d) { }
        virtual double net_price(std::size_t n) const override = 0;
private:
        std::size_t quanlity;
        double discount;
};

class Bulk_quote : public Disc_quote
{
public:
        Bulk_quote() = default;
        Bulk_quote(const std::string &str, double disc, std::size_t q, double p) :
                        Disc_quote(str, p, q, disc) { }

        double net_price(std::size_t n) const override;
private:
        double discount = 0.0;
        std::size_t min_qty = 0;
};

class Limit_quote : public Quote
{
public:
        Limit_quote() = default;
        Limit_quote(const std::string &str, double p, std::size_t num, double d):
                Quote(str, p), max_qty(num), discount(d) { }
        double net_price(std::size_t n) const override;
private:
        std::size_t max_qty = 0;
        double discount = 0.0;
};

double Limit_quote::net_price(std::size_t n) const
{
        if(n > max_qty)
                return max_qty * price * discount + (n - max_qty) * price;
        else
                return n * discount * price;
}

double Bulk_quote::net_price(std::size_t n) const
{   
        if(n >= min_qty)
            return n*(1-discount)*price;
        else
            return n*price;
}

void Quote::debug()
{
    std::cout << "bookNo: "<< bookNo << " price: " << price << std::endl;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
        double ret = item.net_price(n);
        os << "ISBN: " << item.isbn() << " sold: " << n << " total due:";
}


int main()
{

}