require __dir__ + "/spec_helper"
require __dir__ + '/../fp07_05.rb'


describe "演習5" do
  describe "binsort(a)" do
    it "binsort([999,999999,9,99,3,1])" do
      results = binsort([999,999999,9,99,3,1])
      expect(results).to match_array( [1,3,9,99,999,999999])
    end
  end
end
