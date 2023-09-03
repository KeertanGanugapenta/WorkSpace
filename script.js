var swiper = new Swiper(".slide-container", {
  slidesPerView: 4,
  centeredSlides: true,
  spaceBetween: 20,
  slidesPerGroup: 4,
  loop: true,
  centerSlide: "true",
  grabCursor: "true",
  fade: "true",
  pagination: {
    el: ".swiper-pagination",
    clickable: true,
    dynamicBullets: true,
  },
  navigation: {
    nextEl: ".swiper-button-next",
    prevEl: ".swiper-button-prev",
  },

  breakpoints: {
    0: {
      slidersPerView: 1,
    },
    520: {
      slidersPerView: 2,
    },
    768: {
      slidersPerView: 3,
    },
    1000: {
      slidersPerView: 4,
    },
  },
});
