// 2678. Number of Senior Citizens
// Easy one

// did in js because of ease of substr function.

var countSeniors = function (details) {
  let res = 0;
  details.forEach((detail) => {
    if (parseInt(detail.substr(11, 2)) > 60) res++;
  });
  return res;
};
