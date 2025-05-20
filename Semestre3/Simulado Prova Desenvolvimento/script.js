// Carousel functionality
document.addEventListener('DOMContentLoaded', function() {
    const carousel = document.querySelector('.carousel');
    const carouselItems = document.querySelectorAll('.carousel-item');
    const prevBtn = document.querySelector('.prev-btn');
    const nextBtn = document.querySelector('.next-btn');
    const itemWidth = carouselItems[0].offsetWidth + 30; // width + gap
    let currentPosition = 0;
    const itemsVisible = 5; // Número de itens visíveis
    const totalItems = carouselItems.length;

    // Clone os primeiros itens e adicione ao final para efeito infinito
    const firstItems = Array.from(carouselItems).slice(0, itemsVisible);
    firstItems.forEach(item => {
        const clone = item.cloneNode(true);
        carousel.appendChild(clone);
    });

    // Clone os últimos itens e adicione no início para efeito infinito
    const lastItems = Array.from(carouselItems).slice(-itemsVisible);
    lastItems.reverse().forEach(item => {
        const clone = item.cloneNode(true);
        carousel.insertBefore(clone, carousel.firstChild);
    });

    // Atualize a posição inicial
    currentPosition = -(itemWidth * itemsVisible);
    carousel.style.transform = `translateX(${currentPosition}px)`;

    // Função para navegar para o próximo conjunto de itens
    function next() {
        currentPosition -= itemWidth;
        carousel.style.transition = 'transform 0.5s ease';
        carousel.style.transform = `translateX(${currentPosition}px)`;
        
        // Verifique se chegou ao final dos itens originais
        setTimeout(() => {
            if (currentPosition <= -(itemWidth * (totalItems + itemsVisible))) {
                currentPosition = -(itemWidth * itemsVisible);
                carousel.style.transition = 'none';
                carousel.style.transform = `translateX(${currentPosition}px)`;
            }
        }, 500);
    }

    // Função para navegar para o conjunto anterior de itens
    function prev() {
        currentPosition += itemWidth;
        carousel.style.transition = 'transform 0.5s ease';
        carousel.style.transform = `translateX(${currentPosition}px)`;
        
        // Verifique se voltou ao início dos itens originais
        setTimeout(() => {
            if (currentPosition >= -(itemWidth * (itemsVisible - 1))) {
                currentPosition = -(itemWidth * (totalItems + itemsVisible - 1));
                carousel.style.transition = 'none';
                carousel.style.transform = `translateX(${currentPosition}px)`;
            }
        }, 500);
    }

    // Event listeners para os botões
    nextBtn.addEventListener('click', next);
    prevBtn.addEventListener('click', prev);

    // Auto-rotate carousel every 5 seconds
    let carouselInterval = setInterval(next, 5000);

    // Pause auto-rotation on hover
    const carouselContainer = document.querySelector('.carousel-container');
    carouselContainer.addEventListener('mouseenter', function() {
        clearInterval(carouselInterval);
    });

    carouselContainer.addEventListener('mouseleave', function() {
        carouselInterval = setInterval(next, 5000);
    });

    // Ajustar o carrossel no redimensionamento da tela
    window.addEventListener('resize', function() {
        itemWidth = carouselItems[0].offsetWidth + 30;
        carousel.style.transition = 'none';
        carousel.style.transform = `translateX(${currentPosition}px)`;
    });
});