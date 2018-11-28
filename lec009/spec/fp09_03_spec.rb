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
end
