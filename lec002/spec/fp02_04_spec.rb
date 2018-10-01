require __dir__ + "/spec_helper"
require __dir__ + '/../fp02_04.rb'

describe "演習4" do
  describe "a" do
    it "a(2)" do
      puts("a(2)")
      results = a(2)
      puts(results)
      expect(results).to eq 4
    end
    it "a(2)" do
      puts("a(2)")
      results = a(4)
      puts(results)
      expect(results).to eq 16
    end
    it "a(nil)" do
      results = a(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "b" do
    it "b(3)" do
      puts("b(3)")
      results = b(3)
      puts(results)
      expect(results).to eq 6
    end
    it "b(4)" do
      puts("b(4)")
      results = b(4)
      puts(results)
      expect(results).to eq 24
    end
    it "b(nil)" do
      results = b(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "c" do
    it "c(5,2)" do
      puts("c(5,2)")
      results = c(5,2)
      puts(results)
      expect(results).to eq 10
    end
    it "c(7,3)" do
      puts("c(7,3)")
      results = c(7,3)
      puts(results)
      expect(results).to eq 35
    end
    it "c(2,2)" do
      puts("c(2,2)")
      results = c(2,2)
      puts(results)
      expect(results).to eq 1
    end
    it "c(1,nil)" do
      results = c(1,nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "d" do
    it "d(1,7)" do
      #puts("d(1,7)")
      results = d(1,7)
      #puts(results)
      expect(results[0].to_s).to match(/^[-]*?[0-9]{1}\.[0-9]+[e]*?[+-]*?[0-9]*?$/)
      expect(results[1].to_s).to match(/^[-]*?[0-9]{1}\.[0-9]+[e]*?[+-]*?[0-9]*?$/)
    end
    it "d(0,0)" do
      #puts("d(0,0)")
      results = d(0,0)
      #puts(results)
      expect(results[0].to_s).to match(/^[-]*?[0-9]{1}\.[0-9]+[e]*?[+-]*?[0-9]*?$/)
      expect(results[1].to_s).to match(/^[-]*?[0-9]{1}\.[0-9]+[e]*?[+-]*?[0-9]*?$/)
    end
    it "d(0,nil)" do
      #puts("d(0,nil)")
      results = d(0,1)
      #puts(results)
      expect(results[0].to_s).to match(/^[-]*?[0-9]{1}\.[0-9]+[e]*?[+-]*?[0-9]*?$/)
      expect(results[1].to_s).to match(/^[-]*?[0-9]{1}\.[0-9]+[e]*?[+-]*?[0-9]*?$/)
    end
    it "d(1,nil)" do
      results = d(1,nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "x_n" do
    it "x_n(2.0,2)" do
      results = x_n(2.0,2)
      expect(results).to eq 4.0
    end
    it "x_n(3.3)" do
      results = x_n(3,3)
      expect(results).to eq 27
    end
    it "x_n(2,nil)" do
      results = x_n(2,nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "factorial" do
    it "factorial(3)" do
      results = factorial(3)
      expect(results).to eq 6
    end
    it "factorial(3)" do
      results = factorial(4.0)
      expect(results).to eq 24.0
    end
    it "factorial(nil)" do
      results = factorial(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
end
