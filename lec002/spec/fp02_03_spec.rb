require __dir__ + "/spec_helper"
require __dir__ + '/../fp02_03.rb'

describe "演習3" do
  it "integ2(1.0,10.0,100)" do
    puts("integ2(1.0,10.0,100)")
    results = integ2(1.0,10.0,100)
    puts(results)
    expect(results.to_s).to match(/^328.5571[0-9]+/)
  end
  it "integ2(1.0,10.0,1000)" do
    puts("integ2(1.0,10.0,1000)")
    results = integ2(1.0,10.0,1000)
    puts(results)
    expect(results.to_s).to match(/^332.554621[0-9]+/)
  end
  it "integ2(1.0,10.0,10000)" do
    puts("integ2(1.0,10.0,10000)")
    results = integ2(1.0,10.0,10000)
    puts(results)
    expect(results.to_s).to match(/^332.95545121[0-9]+/)
  end
end
