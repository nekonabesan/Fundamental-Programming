require __dir__ + "/spec_helper"
require __dir__ + '/../fp01_01.rb'


describe "演習1" do
  it "Include Array 8" do
    results = e(8)
    expect(results).to match_array([8])
  end
end
