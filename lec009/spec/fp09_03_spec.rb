require __dir__ + "/spec_helper"
require __dir__ + '/../fp09_03.rb'
require __dir__ + '/../app/models/ratio.rb'


describe "演習 3" do
  context "Ratio" do
    it "Ratio.new(3,5)" do
      obj = Ratio.new(3,5)
      results = obj.to_s
      expect(results).to match("3/5")
    end
    it " Ratio.new(8,7)" do
      obj = Ratio.new(8,7)
      results = obj.to_s
      expect(results).to match("8/7")
    end
    it "a + b" do
      a = Ratio.new(3,5)
      b = Ratio.new(8,7)
      results = a + b
      expect(results.to_s).to match("61/35")
    end
  end
end
