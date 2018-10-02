require __dir__ + "/spec_helper"
require __dir__ + '/../fp04_04.rb'

describe "演習4" do
  context "gcd 1" do
    it "gcd" do
      results = gcd(21,27)
      expect(results).to match(3)
    end
    it "gcd" do
      results = gcd(24,36)
      expect(results).to match(12)
    end
    it "gcd" do
      results = gcd(24,'jh')
      expect(results).to be_a(ArgumentError)
    end
  end
  context "fact" do
    it "fact(3)" do
      results = fact(3)
      expect(results).to match(6)
    end
    it "fact(4)" do
      results = fact(4)
      expect(results).to match(24)
    end
    it "fact(1)" do
      results = fact(1)
      expect(results).to match(1)
    end
    it "fact(nil)" do
      results = fact(nil)
      expect(results).to be_a(ArgumentError)
    end
    it "fact(-1)" do
      results = fact(-1)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "fib" do
    it "fib(0)" do
      results = fib(0)
      expect(results).to eq 1
    end
    it "fib(0)" do
      results = fib(1)
      expect(results).to eq 1
    end
    it "fib(0)" do
      results = fib(2)
      expect(results).to eq 2
    end
    it "fib(0)" do
      results = fib(3)
      expect(results).to eq 3
    end
    it "fib(0)" do
      results = fib(4)
      expect(results).to eq 5
    end
    it "fib(0)" do
      results = fib(5)
      expect(results).to eq 8
    end
    it "fib(0)" do
      results = fib(6)
      expect(results).to eq 13
    end
    it "fib(-1)" do
      results = fib(-1)
      expect(results).to be_a(ArgumentError)
    end
    it "fib(nil)" do
      results = fib(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "comb" do
    it "comb(5,2)" do
      results = comb(5,2)
      expect(results).to eq 10
    end
    it "comb(7,3)" do
      results = comb(7,3)
      expect(results).to eq 35
    end
    it "comb(3,3)" do
      results = comb(3,3)
      expect(results).to eq 1
    end
    it "comb(4,0)" do
      results = comb(4,0)
      expect(results).to eq 1
    end
    it "comb(3,nil)" do
      results = comb(3,nil)
      expect(results).to be_a(ArgumentError)
    end
    it "comb(nil,3)" do
      results = comb(nil,3)
      expect(results).to be_a(ArgumentError)
    end
    it "comb(2,3)" do
      results = comb(2,3)
      expect(results).to be_a(ArgumentError)
    end
    it "comb(-1,3)" do
      results = comb(-1,3)
      expect(results).to be_a(ArgumentError)
    end
    it "comb(1,-3)" do
      results = comb(1,-3)
      expect(results).to be_a(ArgumentError)
    end
  end
end
