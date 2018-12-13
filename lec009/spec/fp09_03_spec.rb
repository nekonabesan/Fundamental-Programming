require __dir__ + "/spec_helper"
require __dir__ + '/../fp09_03.rb'
require __dir__ + '/../app/models/ratio.rb'


describe "演習 3 Ratio" do
  context "Ratio initialize" do
    it "Ratio.new(3,0)" do
      obj = Ratio.new(3,0)
      results = obj
      expect(results.to_s).to match("3/0")
    end
    it "Ratio.new(0,3)" do
      obj = Ratio.new(0,3)
      results = obj
      expect(results.to_s).to match("0/3")
    end
    it "Ratio.new(3,5)" do
      obj = Ratio.new(3,5)
      results = obj
      expect(results.to_s).to match("3/5")
    end
    it " Ratio.new(8,7)" do
      obj = Ratio.new(8,7)
      results = obj
      expect(results.to_s).to match("8/7")
    end
  end
  context "Ratio add" do
    it "add" do
      a = Ratio.new(3,5)
      b = Ratio.new(8,7)
      results = a.add(b)
      expect(results.to_s).to match("61/35")
    end
    it "add" do
      a = Ratio.new(1,2)
      b = Ratio.new(1,3)
      results = a.add(b);
      expect(results.to_s).to match("5/6")
    end
  end
  context "Ratio subtraction" do
    it "subtraction 01 throw exception" do
      a = Ratio.new(1,4)
      results = a.subtraction(nil)
      expect(results).to be_a(ArgumentError)
    end
    it "subtraction" do
      a = Ratio.new(1,4)
      b = Ratio.new(1,5)
      results = a.subtraction(b)
      expect(results.to_s).to match("1/20")
    end
  end
  context "Ratio times" do
    it "times 01 throw exception" do
      a = Ratio.new(1,4)
      results = a.times(nil)
      expect(results).to be_a(ArgumentError)
    end
    it "times 02" do
      a = Ratio.new(1,4)
      b = Ratio.new(1,5)
      results = a.times(b)
      expect(results.to_s).to match("1/20")
    end
    it "times 03" do
      a = Ratio.new(2,3)
      b = Ratio.new(1,5)
      results = a.times(b)
      expect(results.to_s).to match("2/15")
    end
  end
  context "Ratio div" do
    it "div 01 throw exception" do
      a = Ratio.new(1,3)
      results = a.div(nil)
      expect(results).to be_a(ArgumentError)
    end
    it "div 02" do
      a = Ratio.new(1,3)
      b = Ratio.new(1,5)
      results = a.div(b)
      expect(results.to_s).to match("5/3")
    end
    it "div 03" do
      a = Ratio.new(1,4)
      b = Ratio.new(4)
      results = a.div(b)
      expect(results.to_s).to match("1/1")
    end
  end
end
